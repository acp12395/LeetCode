class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool retVal = true;
        unordered_map<char, char> charMap;
        for(int charIndex = 0; charIndex < s.size(); charIndex++)
        {
            if(charMap.contains(s[charIndex]))
            {
                if(charMap[s[charIndex]] != t[charIndex])
                {
                    retVal = false;
                    break;
                }
            }
            else
            {
                for(auto& [charS,charT] : charMap)
                {
                    if(charT == t[charIndex])
                    {
                        retVal = false;
                        break;
                    }
                }
                charMap[s[charIndex]] = t[charIndex];
            }
        }
        return retVal;
    }
};