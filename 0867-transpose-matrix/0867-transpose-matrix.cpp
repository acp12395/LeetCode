class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> outputMatrix;
        for(int n = 0; n < matrix[0].size(); n++)
        {
            int outputRow = n;
            
            vector<int> outputRowVector;
            outputMatrix.push_back(outputRowVector);
            for(int m = 0; m < matrix.size(); m++)
            {
                outputMatrix[outputRow].push_back(matrix[m][n]);
            }
        }
        return outputMatrix;
    }
};