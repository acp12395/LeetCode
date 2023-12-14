class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> diff(grid.size());
        vector<int> onesMinusZerosRows(grid.size());
        vector<int> onesMinusZerosColumns(grid[0].size());
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 0)
                {
                    onesMinusZerosRows[i]--;
                    onesMinusZerosColumns[j]--;
                }
                else
                {
                    onesMinusZerosRows[i]++;
                    onesMinusZerosColumns[j]++;
                }
            }
        }
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                diff[i].push_back(onesMinusZerosRows[i] + onesMinusZerosColumns[j]);
            }
        }
        return diff;
    }
};