class Solution {
private:
    vector<string> wordBreakHelper(string remainingString,
         unordered_set<string>& wordDict,
         unordered_map<string, vector<string>>& memo)
    {
        if(memo.count(remainingString))
        {
            return memo[remainingString];
        }
        vector<string> resultStrings;
        if(remainingString == "")
        {
            resultStrings.push_back(remainingString);
            return resultStrings;
        }
        for(int i = 1; i <= remainingString.size(); i++)
        {
            string currSubstring = remainingString.substr(0, i);
            if(wordDict.count(currSubstring))
            {
                vector<string> nextRemainingStringResult =
                    wordBreakHelper(remainingString.substr(i),wordDict,memo);
                for(const string& nextString : nextRemainingStringResult)
                {
                    resultStrings.push_back(currSubstring + (nextString == "" ? "" : " ") + nextString);
                }
            }
        }
        memo[remainingString] = resultStrings;
        return resultStrings;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> memoMap;
        unordered_set<string> words = {wordDict.begin(), wordDict.end()};
        return wordBreakHelper(s, words, memoMap);
    }
};