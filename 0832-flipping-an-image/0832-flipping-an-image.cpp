class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> retVec;
        for(auto& row : image)
        {
            vector<int> resultingRow;
            for(auto column = row.rbegin(); column < row.rend(); ++column)
            {
                switch (*column)
                {
                case 0:
                    resultingRow.push_back(1);
                    break;
                case 1:
                    resultingRow.push_back(0);
                    break;
                default:
                    break;
                }
            }
            retVec.push_back(resultingRow);
        }
        return retVec;
    }
};