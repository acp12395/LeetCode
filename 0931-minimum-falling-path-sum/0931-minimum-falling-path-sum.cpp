class Solution {
private: 
    int minFallingPathSumHelper(vector<vector<int>>& matrix, vector<vector<int>>& minPathSumMatrix, pair<int,int> coord)
    {
        if(coord.first == matrix.size() - 1)
        {
            minPathSumMatrix[coord.first][coord.second] = matrix[coord.first][coord.second];
        }
        else if(minPathSumMatrix[coord.first][coord.second] == INT_MAX)
        {
            int downLeft = INT_MAX;
            int down = minFallingPathSumHelper(matrix, minPathSumMatrix, {coord.first + 1, coord.second});
            int downRight = INT_MAX;
            if(coord.second > 0)
            {
                downLeft = minFallingPathSumHelper(matrix, minPathSumMatrix, {coord.first + 1, coord.second - 1});
            }
            if(coord.second < matrix.size() - 1)
            {
                downRight = minFallingPathSumHelper(matrix, minPathSumMatrix, {coord.first + 1, coord.second + 1});
            }
            int minVal = min(down, downLeft);
            minVal = min(minVal, downRight);
            minPathSumMatrix[coord.first][coord.second] = matrix[coord.first][coord.second] + minVal;
        }
        return minPathSumMatrix[coord.first][coord.second];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minVal = INT_MAX;
        vector<vector<int>> minPathSumMatrix(matrix.size(), vector<int>(matrix.size(), INT_MAX));
        for(int index = 0; index < matrix.size(); index++)
        {
            minVal = min(minVal, minFallingPathSumHelper(matrix, minPathSumMatrix, {0, index}));
        }
        return minVal;
    }
};