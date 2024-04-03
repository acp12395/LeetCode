class Solution {
private:
    bool existHelper(vector<vector<char>>& board, string& word, int& reachedChar, int& rowIndex, int& colIndex, unordered_map<int,pair<int,int>>& seqMap)
    {
        bool doesExist = false;
        if(reachedChar == word.size())
        {
            doesExist = true;
        }
        else
        {
            int row, col;
            for(row = rowIndex - 1; row <= rowIndex + 1; row++)
            {
                for(col = colIndex - 1; col <= colIndex + 1; col++)
                {
                    if(row >= 0 && row < board.size() && col >= 0 && col < board[0].size())
                    {
                        if(board[row][col] == word[reachedChar])
                        {
                            if((col == colIndex && (row == rowIndex - 1 || row == rowIndex + 1)) ||
                                (row == rowIndex && (col == colIndex -1 || col == colIndex + 1)))
                            {
                                bool isPrevious = false;
                                for(auto& [_,coordinate] : seqMap)
                                {
                                    if(coordinate.first == row && coordinate.second == col)
                                    {
                                        isPrevious = true;
                                        break;
                                    }
                                }
                                if(!isPrevious)
                                {
                                    reachedChar++;
                                    seqMap[reachedChar] = {row,col};
                                    doesExist |= existHelper(board, word, reachedChar, row, col, seqMap);
                                    seqMap.erase(reachedChar);
                                    reachedChar--;
                                }
                            }
                        }
                    }
                }
            }
        }
        return doesExist;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int doesExist = false;
        int reached = 0;
        unordered_map<int,pair<int,int>> charIndexCoordinateMap;
        for(int rowIndex = 0; rowIndex < board.size() && !doesExist; rowIndex++)
        {
            for(int colIndex = 0; colIndex < board[0].size() && !doesExist; colIndex++)
            {
                if(board[rowIndex][colIndex] == word[reached])
                {
                    reached++;
                    charIndexCoordinateMap[reached] = {rowIndex,colIndex};
                    doesExist |= existHelper(board, word, reached, rowIndex, colIndex, charIndexCoordinateMap);
                    charIndexCoordinateMap.erase(reached);
                    reached--;
                }
            }
        }
        return doesExist;
    }
};