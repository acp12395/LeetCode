class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(auto& num : grid)
        {
            if(num[0] == 0)
            {
                for(auto& cell : num)
                {
                    if(cell == 0)
                    {
                        cell = 1;
                    }
                    else
                    {
                        cell = 0;
                    }
                }
            }
        }
        int res = 0;
        for(int col = 0; col < grid[0].size(); col++)
        {
            int countZeros = 0;
            int countOnes = 0;
            for(int row = 0; row < grid.size(); row++)
            {
                if(grid[row][col] == 0)
                {
                    countZeros++;
                }
                else
                {
                    countOnes++;
                }
            }
            res += pow(2, grid[0].size() - col - 1)*(max(countZeros,countOnes));
        }
        return res;
    }
};