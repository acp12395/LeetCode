class Solution {
private:
    void findFarmlandHelper(vector<vector<int>>& land, int row, int col, vector<int>& landCorners)
    {
        if(land[row][col] == 0)
        {
            return;
        }
        else
        {
            land[row][col] = 0;
            if(row > landCorners[2])
            {
                landCorners[2] = row;
            }
            if(col > landCorners[3])
            {
                landCorners[3] = col;
            }
            if(row < land.size() - 1)
            {
                findFarmlandHelper(land, row + 1, col, landCorners);
            }
            if(col < land[0].size() - 1)
            {
                findFarmlandHelper(land, row, col + 1, landCorners);
            }
        }
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> farmlandsCorners;
        vector<vector<int>> l_land = land;
        for(int rowIndex = 0; rowIndex < l_land.size(); rowIndex++)
        {
            for(int colIndex = 0; colIndex < l_land[0].size(); colIndex++)
            {
                if(l_land[rowIndex][colIndex] == 1)
                {
                    vector<int> landCorners;
                    landCorners.push_back(rowIndex);
                    landCorners.push_back(colIndex);
                    landCorners.push_back(rowIndex);
                    landCorners.push_back(colIndex);
                    findFarmlandHelper(l_land, rowIndex, colIndex, landCorners);
                    farmlandsCorners.push_back(landCorners);
                }
            }
        }
        return farmlandsCorners;
    }
};