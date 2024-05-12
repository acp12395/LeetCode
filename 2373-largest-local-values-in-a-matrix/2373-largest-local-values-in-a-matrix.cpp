class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> resGrid;
        for(int row = 1; row < grid.size() - 1; row++)
        {
            vector<int> pushVec;
            resGrid.push_back(pushVec);
            for(int col = 1; col < grid[0].size() - 1; col++)
            {
                int max = 0;
                for(int row3x3 = row - 1; row3x3 <= row + 1; row3x3++)
                {
                    for(int col3x3 = col - 1; col3x3 <= col + 1; col3x3++)
                    {
                        max = max < grid[row3x3][col3x3] ? grid[row3x3][col3x3] : max;
                    }
                }
                resGrid[row - 1].push_back(max);
            }
        }
        return resGrid;
    }
};