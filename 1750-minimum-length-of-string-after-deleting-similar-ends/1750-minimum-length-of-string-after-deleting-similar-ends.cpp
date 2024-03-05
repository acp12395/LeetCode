class Solution {
public:
    int minimumLength(string s) {
        int prefix = 0, suffix = s.size() - 1, minLength = s.size();
        char prefixChar = s[prefix], suffixChar = s[suffix];
        while(s[prefix] == s[suffix] && prefix < suffix)
        {
            while(s[prefix] == prefixChar && prefix < s.size() - 1)
            {
                prefix++;
            }
            prefixChar = s[prefix];
            while(s[suffix] == suffixChar && 0 < suffix)
            {
                suffix--;
            }
            suffixChar = s[suffix];
            minLength = suffix - prefix + 1;
        }
        if(prefix > suffix)
        {
            minLength = 0;
        }
        return minLength;
    }
};