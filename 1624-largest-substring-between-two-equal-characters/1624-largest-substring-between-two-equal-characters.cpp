class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxLength = -1;
        int length;
        unordered_map<char,int> lengthsMap;
        for(int charIndex = 0; charIndex <= s.size(); charIndex++)
        {
            if(lengthsMap.count(s[charIndex]) == 1)
            {
                length = charIndex - lengthsMap[s[charIndex]]- 1;
                if(length > maxLength)
                {
                    maxLength = length;
                }
            }
            else
            {
                lengthsMap[s[charIndex]] = charIndex;
            }
        }
        return maxLength;
    }
};