class Solution {
private:
    int uniquePathsWithObstaclesHelper(vector<vector<int>>& obstacleGrid, vector<vector<int>>& uniquePathsGrid, pair<int, int> coord)
    {
        if(obstacleGrid[coord.first][coord.second] == 1)
        {
            uniquePathsGrid[coord.first][coord.second] = 0;
        }
        else if(uniquePathsGrid[coord.first][coord.second] < 0)
        {
            if(coord.first == 0 && coord.second == 0)
            {
                if(obstacleGrid[coord.first][coord.second] == 0)
                {
                    uniquePathsGrid[coord.first][coord.second] = 1;
                }
            }
            else
            {
                int left = 0;
                int up = 0;
                if(obstacleGrid[coord.first][coord.second] == 0)
                {
                    if(coord.first > 0)
                    {
                        up = uniquePathsWithObstaclesHelper(obstacleGrid, uniquePathsGrid, {coord.first - 1, coord.second});
                    }
                    if(coord.second > 0)
                    {
                        left = uniquePathsWithObstaclesHelper(obstacleGrid, uniquePathsGrid, {coord.first, coord.second - 1});
                    }
                }
                uniquePathsGrid[coord.first][coord.second] = up + left;
            }
        }
        return uniquePathsGrid[coord.first][coord.second];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> uniquePathsGrid(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),-1));
        return uniquePathsWithObstaclesHelper(obstacleGrid, uniquePathsGrid, {obstacleGrid.size() - 1, obstacleGrid[0].size() - 1});
    }
};