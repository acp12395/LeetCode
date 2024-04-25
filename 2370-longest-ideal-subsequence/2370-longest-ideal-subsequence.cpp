class Solution {
public:
    int longestIdealString(string s, int k) {
        int maxLength = 0;
        unordered_map<char, int> charLastOccurLength;
        for(auto character = s.rbegin(); character < s.rend(); character++)
        {
            int length = 0;
            char leftLim = 'a' > *character - k ? 'a' : *character - k;
            char rightLim = 'z' < *character + k ? 'z' : *character + k;
            for(char i = leftLim; i <= rightLim; i++)
            {
                length = length > charLastOccurLength[i] ? length : charLastOccurLength[i];
            }
            charLastOccurLength[*character] = length + 1;
        }
        for(auto& [_, length] : charLastOccurLength)
        {
            maxLength = maxLength > length ? maxLength : length;
        }
        return maxLength;
    }
};