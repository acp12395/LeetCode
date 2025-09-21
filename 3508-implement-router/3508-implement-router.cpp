class Router {
private:
    int memory;
    int usedMemory;
    queue<vector<int>> packetsQ;
    unordered_map<int, unordered_map<int, vector<int>>> packetsMap;
    unordered_map<int, vector<int>> destTimeStampsMap;
public:
    Router(int memoryLimit) {
        memory = memoryLimit;
        usedMemory = 0;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(packetsMap.count(source) == 1 && packetsMap[source].count(destination) == 1 && packetsMap[source][destination].back() == timestamp)
        {
            return false;
        }
        else
        {
            if(packetsMap.count(source) == 0)
            {
                packetsMap.insert({source, unordered_map<int, vector<int>>()});
            }
            else
            {
                if(packetsMap[source].count(destination) == 0)
                {
                    packetsMap[source].insert({destination,vector<int>()});
                }
            }
        }

        bool retVal = false;
        if(packetsMap[source][destination].size() == 0 || packetsMap[source][destination].size() > 0 && packetsMap[source][destination].back() != timestamp)
        {
            if(usedMemory == memory)
            {
                forwardPacket();
            }
            usedMemory++;
            packetsMap[source][destination].push_back(timestamp);
            packetsQ.push({source, destination, timestamp});
            destTimeStampsMap[destination].push_back(timestamp);
            retVal = true;
        }
        return retVal;
    }
    
    vector<int> forwardPacket() {
        vector<int> removePacket;
        if(!packetsQ.empty())
        {
            removePacket = packetsQ.front();
            packetsMap[removePacket[0]][removePacket[1]].erase(packetsMap[removePacket[0]][removePacket[1]].begin());
            if(packetsMap[removePacket[0]][removePacket[1]].empty())
            {
                packetsMap[removePacket[0]].erase(removePacket[1]);
                if(packetsMap[removePacket[0]].empty())
                {
                    packetsMap.erase(removePacket[0]);
                }
            }
            destTimeStampsMap[removePacket[1]].erase(destTimeStampsMap[removePacket[1]].begin());
            if(destTimeStampsMap[removePacket[1]].empty())
            {
                destTimeStampsMap.erase(removePacket[1]);
            }
            packetsQ.pop();
            usedMemory--;
        }
        return removePacket;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(destTimeStampsMap.count(destination) == 1)
        {
            int lower = (int)(lower_bound(destTimeStampsMap[destination].begin(), destTimeStampsMap[destination].end(), startTime) - destTimeStampsMap[destination].begin());
            int upper = (int)(upper_bound(destTimeStampsMap[destination].begin(), destTimeStampsMap[destination].end(), endTime) - destTimeStampsMap[destination].begin());
            return upper - lower;
        }
        return 0;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */