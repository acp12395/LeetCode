class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int turns = -1;
        int intTarget = stoi(target);
        vector<int> visited(10000,-1);
        for(auto& deadend : deadends)
        {
            visited[stoi(deadend)] = 0;
        }
        unordered_map<int,vector<int>> nodeAdjacentNodes;
        for(int combination = 0; combination < 10000; combination++)
        {
            for(int digitIndex = 0; digitIndex <= 3; digitIndex++)
            {
                int digit = (combination/static_cast<int>(pow(10,digitIndex)))%10;
                int newComb = combination - digit*pow(10,digitIndex);
                if(digit < 9)
                {
                      digit++;
                }
                else
                {
                    digit = 0;
                }
                nodeAdjacentNodes[combination].push_back(newComb + digit*pow(10,digitIndex));
                if(digit > 1)
                {
                    digit = digit - 2;
                }
                else if(digit == 1)
                {
                    digit = 9;
                }
                else
                {
                    digit = 8;
                }
                nodeAdjacentNodes[combination].push_back(newComb + digit*pow(10,digitIndex));
            }
        }
        queue<int> visitNodesQueue;
        visitNodesQueue.push(0);
        if(visited[0] == -1)
        {
            visited[0] = 0;
            while(!visitNodesQueue.empty())
            {
                if(intTarget == visitNodesQueue.front())
                {
                    return visited[visitNodesQueue.front()];
                }
                for(auto& node : nodeAdjacentNodes[visitNodesQueue.front()])
                {
                    if(visited[node] == -1)
                    {
                        visitNodesQueue.push(node);
                        visited[node] = visited[visitNodesQueue.front()] + 1;
                    }
                }
                visitNodesQueue.pop();
            }
        }
        return turns;
    }
};