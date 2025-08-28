class Solution {
private:
    int minPathSumHelper(map<pair<int,int>, int>& coordMinMap, pair<int, int> coord, vector<vector<int>>& grid)
    {
        int retVal = INT_MAX;
        if(coord.first == 0 && coord.second == 0)
        {
            retVal = grid[coord.first][coord.second];
        }
        else if(coordMinMap.count({coord.first, coord.second}) == 1)
        {
            retVal = coordMinMap[{coord.first, coord.second}];
        }
        else
        {
            int up = INT_MAX;
            int left = INT_MAX;
            if(coord.first > 0)
            {
                pair<int,int> upCoord = {coord.first - 1, coord.second};
                up = minPathSumHelper(coordMinMap, upCoord, grid);
            }
            if(coord.second > 0)
            {
                pair<int,int> leftCoord = {coord.first, coord.second - 1};
                left = minPathSumHelper(coordMinMap, leftCoord, grid);
            }
            coordMinMap[coord] = grid[coord.first][coord.second] + min(left, up);
            retVal = coordMinMap[coord];
        }
        return retVal;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        map<pair<int,int>, int> coordMinMap;
        return minPathSumHelper(coordMinMap, {grid.size() - 1, grid[0].size() - 1}, grid);
    }
};