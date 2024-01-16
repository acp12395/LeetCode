class RandomizedSet {
private:
    unordered_map<int,int> randomMap;
    vector<int> randomVec;
public:
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if(randomMap.contains(val))
        {
            return false;
        }
        else
        {
            randomVec.push_back(val);
            randomMap[val] = randomVec.size() - 1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(randomMap.contains(val))
        {
            int index = randomMap[val];
            swap(randomVec[index], randomVec[randomVec.size()-1]);
            randomVec.pop_back();
            randomMap[randomVec[index]] = index;
            randomMap.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int getRandom() {
        return randomVec[rand()%randomVec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */