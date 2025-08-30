class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowSets(9);
        vector<unordered_set<char>> columnSets(9);
        vector<vector<unordered_set<char>>> subBoxSets(3, vector<unordered_set<char>>(3));
        for(int rowIndex = 0; rowIndex < 9; rowIndex++)
        {
            for(int columnIndex = 0; columnIndex < 9; columnIndex++)
            {
                char currentVal = board[rowIndex][columnIndex];
                if(currentVal != '.')
                {
                    if(rowSets[rowIndex].insert(currentVal).second == false)
                    {
                        return false;
                    }
                    if(columnSets[columnIndex].insert(currentVal).second == false)
                    {
                        return false;
                    }
                    if(subBoxSets[rowIndex / 3][columnIndex / 3].insert(currentVal).second == false) 
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};