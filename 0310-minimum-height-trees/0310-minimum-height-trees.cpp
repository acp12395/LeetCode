class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,unordered_map<int,int>> nodeAdjacentNodes;
        for(auto& edge : edges)
        {
            nodeAdjacentNodes[edge[0]][edge[1]] = 0;
            nodeAdjacentNodes[edge[1]][edge[0]] = 0;
        }
        queue<pair<int,unordered_map<int,int>>> trimQueue;
        while(nodeAdjacentNodes.size() > 2)
        {
            for(auto& edge : nodeAdjacentNodes)
            {
                if(edge.second.size() == 1)
                {
                    trimQueue.push(edge);
                }
            }
            while(trimQueue.size() > 0)
            {
                int trimNode = trimQueue.front().first;
                int trimNodeBranch;
                for(auto& node : trimQueue.front().second)
                {
                    trimNodeBranch = node.first;
                }
                nodeAdjacentNodes[trimNodeBranch].erase(trimNode);
                nodeAdjacentNodes.erase(trimNode);
                trimQueue.pop();
            }
        }
        vector<int> MHTRoots;
        if(nodeAdjacentNodes.size() == 0)
        {
            MHTRoots.push_back(0);
        }
        else
        {
            for(auto& [root,_] : nodeAdjacentNodes)
            {
                MHTRoots.push_back(root);
            }
        }
        return MHTRoots;
    }
};