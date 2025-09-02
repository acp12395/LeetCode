class Solution {
private:
    int maxSquare;
    int maximalSquareHelper(vector<vector<char>>& matrix, vector<vector<int>>& maxSquareMatrix, pair<int,int> coord)
    {
        if(coord.first == matrix.size() - 1 && coord.second == matrix[0].size() - 1)
        {
            maxSquareMatrix[coord.first][coord.second] = matrix[coord.first][coord.second] - '0';
        }
        else if(maxSquareMatrix[coord.first][coord.second] == -1)
        {
            int right = 0;
            int down = 0;
            int downRight = 0;
            if(coord.first < matrix.size() - 1)
            {
                down = maximalSquareHelper(matrix, maxSquareMatrix, {coord.first + 1, coord.second});
            }
            if(coord.second < matrix[0].size() - 1)
            {
                right = maximalSquareHelper(matrix, maxSquareMatrix, {coord.first, coord.second + 1});
            }
            if(coord.first < matrix.size() - 1 && coord.second < matrix[0].size() - 1)
            {
                downRight = maximalSquareHelper(matrix, maxSquareMatrix, {coord.first + 1, coord.second + 1});
            }
            if(matrix[coord.first][coord.second] - '0' == 0)
            {
                maxSquareMatrix[coord.first][coord.second] = 0;
            }
            else
            {
                int minSquare = min(right, down);
                minSquare = min(minSquare, downRight);
                maxSquareMatrix[coord.first][coord.second] = sqrt(abs(minSquare)) + 1;
                maxSquareMatrix[coord.first][coord.second] = pow(maxSquareMatrix[coord.first][coord.second], 2);
            }
        }
        maxSquare = max(maxSquare, maxSquareMatrix[coord.first][coord.second]);
        return maxSquareMatrix[coord.first][coord.second];
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        maxSquare = 0;
        vector<vector<int>> maxSquareMatrix(matrix.size(), vector<int>(matrix[0].size(), -1));
        maximalSquareHelper(matrix, maxSquareMatrix, {0,0});
        return maxSquare;
    }
};