class Solution {
private:
    int uniquePathsHelper(int x, int y, map<pair<int,int>, int>& cellPathsNumberMap)
    {
        pair<int,int> coord = {x, y};
        if(cellPathsNumberMap.count(coord) == 1)
        {
            return cellPathsNumberMap[coord];
        }
        int leftPaths = 0;
        int upPaths = 0;
        if(x == 0 && y == 0)
        {
            return 1;
        }
        if(x > 0)
        {
            leftPaths = uniquePathsHelper(x - 1, y, cellPathsNumberMap);
        }
        if(y > 0)
        {
            upPaths = uniquePathsHelper(x, y - 1, cellPathsNumberMap);
        }
        cellPathsNumberMap[coord] = leftPaths + upPaths;
        return cellPathsNumberMap[coord];
    }
public:
    int uniquePaths(int m, int n) {
        map<pair<int,int>, int> cellPathsNumberMap;
        return uniquePathsHelper(n - 1, m - 1, cellPathsNumberMap);
    }
};