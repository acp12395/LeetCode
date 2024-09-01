class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> retVec;
        if(original.size() == m*n)
        {
            for(int row = 0; row < m; row++)
            {
                vector<int> newRow;
                retVec.push_back(newRow);
                for(int column = 0; column < n; column++)
                {
                    retVec[row].push_back(original[column + row*n]);
                }
            }
        }
        return retVec;
    }
};