class Solution {
private:
    void partitionHelper(string& s, vector<vector<string>>& partitionedStrings, vector<string>& collectedStrings, int start, int end)
    {
        if(end >= s.size())
        {
            partitionedStrings.push_back(collectedStrings);
        }
        else
        {
            while(end < s.size())
            {
                if(isPalindrome(s, start, end))
                {
                    collectedStrings.push_back(s.substr(start, end - start + 1));
                    partitionHelper(s, partitionedStrings, collectedStrings, end + 1, end + 1);
                    collectedStrings.pop_back();
                }
                end++;
            }
        }
    }
    bool isPalindrome(string& s, int start, int end)
    {
        while(start < end)
        {
            if(s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> partitionedStrings;
        vector<string> collectedStrings;
        int start = 0, end = 0;
        partitionHelper(s, partitionedStrings, collectedStrings, start, end);
        return partitionedStrings;
    }
};