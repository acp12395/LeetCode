class Solution {
private:
    struct ArrayHasher {
        std::size_t operator()(const std::array<int, 3>& a) const {
            std::size_t h = 0;

            for (auto e : a) {
                h ^= std::hash<int>{}(e)  + 0x9e3779b9 + (h << 6) + (h >> 2); 
            }
            return h;
        }   
    };
    unordered_map<array<int,3>,int,ArrayHasher> coordinatePathsNoMap;
    int findPathsHelper(int m, int n, int maxMove, int startRow, int startColumn, unordered_map<array<int,3>,int,ArrayHasher>& coordinatePathsNoMap)
    {
        if(coordinatePathsNoMap.count({startRow,startColumn,maxMove}) == 1)
        {
            return coordinatePathsNoMap[{startRow,startColumn,maxMove}];
        }
        else if(startRow >= m || startRow < 0 || startColumn >= n || startColumn < 0)
        {
            return 1;
        }
        else if(maxMove == 0)
        {
            return 0;
        }
        else
        {
            long int right = findPathsHelper(m, n, maxMove - 1, startRow, startColumn + 1,coordinatePathsNoMap);
            long int left = findPathsHelper(m, n, maxMove - 1, startRow, startColumn - 1,coordinatePathsNoMap);
            long int down = findPathsHelper(m, n, maxMove - 1, startRow + 1, startColumn,coordinatePathsNoMap);
            long int up = findPathsHelper(m, n, maxMove - 1, startRow - 1, startColumn,coordinatePathsNoMap);
            coordinatePathsNoMap[{startRow,startColumn,maxMove}] = (up + down + left + right)%1000000007;
            return coordinatePathsNoMap[{startRow,startColumn,maxMove}];
        }
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        coordinatePathsNoMap.clear();
        return findPathsHelper(m, n, maxMove, startRow, startColumn, coordinatePathsNoMap);
    }
};