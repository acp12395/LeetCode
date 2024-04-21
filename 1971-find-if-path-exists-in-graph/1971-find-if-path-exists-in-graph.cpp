class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> nodeAdjacentNodes;
        for(auto& edge : edges)
        {
            nodeAdjacentNodes[edge[0]].push_back(edge[1]);
            nodeAdjacentNodes[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n);
        queue<int> pathNodesQueue;
        pathNodesQueue.push(source);
        visited[source] = true;
        while(!pathNodesQueue.empty())
        {
            if(pathNodesQueue.front() == destination)
            {
                return true;
            }
            for(auto& adjacentNode : nodeAdjacentNodes[pathNodesQueue.front()])
            {
                if(!visited[adjacentNode])
                {
                    visited[adjacentNode] = true;
                    pathNodesQueue.push(adjacentNode);
                }
            }
            pathNodesQueue.pop();
        }
        return false;
    }
};