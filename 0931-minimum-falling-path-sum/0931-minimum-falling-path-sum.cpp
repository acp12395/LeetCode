class Solution {
private:
    void minFallingPathSumHelper(vector<vector<int>>& matrix, int row = 0)
    {
        if(row != matrix.size() - 1)
        {
            minFallingPathSumHelper(matrix, row + 1);
        }
        int cellNo = row * matrix.size();
        for(int numberIndex = 0; numberIndex < matrix.size(); numberIndex++)
        {
            pathSumMap[cellNo] = matrix[row][numberIndex];
            if(row != matrix.size() - 1)
            {
                int belowL, below, belowR;
                below = pathSumMap[cellNo + matrix.size()];
                if(numberIndex == 0)
                {
                    belowR = pathSumMap[cellNo + matrix.size() + 1];
                    pathSumMap[cellNo] += (below < belowR ? below : belowR);
                }
                else if(numberIndex == matrix.size() - 1)
                {
                    belowL = pathSumMap[cellNo + matrix.size() - 1];
                    pathSumMap[cellNo] += (below < belowL ? below : belowL);
                }
                else
                {
                    belowR = pathSumMap[cellNo + matrix.size() + 1];
                    belowL = pathSumMap[cellNo + matrix.size() - 1];
                    int belowMin = (below < belowL ? below : belowL);
                    belowMin = (belowMin < belowR ? belowMin : belowR);
                    pathSumMap[cellNo] += belowMin;
                }
            }
            cellNo++;
        }
    }
    unordered_map<int, int> pathSumMap;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int retVal = INT_MAX;
        minFallingPathSumHelper(matrix);
        for(int i = 0; i < matrix.size(); i++)
        {
            retVal = retVal < pathSumMap[i] ? retVal : pathSumMap[i];
        }
        return retVal;
    }
};