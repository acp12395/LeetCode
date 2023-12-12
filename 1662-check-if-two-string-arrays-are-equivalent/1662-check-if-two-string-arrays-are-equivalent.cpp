class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word1StringResult;
        string word2StringResult;
        for(auto& i : word1)
        {
            word1StringResult.append(i);
        }
        for(auto& i : word2)
        {
            word2StringResult.append(i);
        }
        return (word1StringResult == word2StringResult) ? true : false;
    }
};