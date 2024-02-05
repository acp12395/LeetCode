class Solution {
public:
    int firstUniqChar(string s) {
        int retVal = -1;
        unordered_map<char, pair<int,int>> charCountIndexMap;
        for(int characterIndex = 0; characterIndex < s.size(); characterIndex++)
        {
            charCountIndexMap[s[characterIndex]].first++;
            if(charCountIndexMap[s[characterIndex]].first == 1)
            {
                charCountIndexMap[s[characterIndex]].second = characterIndex;
            }
        }
        int indexSelector = INT_MAX;
        for(auto char_countIndex = charCountIndexMap.begin(); char_countIndex != charCountIndexMap.end(); char_countIndex++)
        {
            if((*char_countIndex).second.first == 1)
            {
                if((*char_countIndex).second.second < indexSelector)
                {
                    indexSelector = (*char_countIndex).second.second;
                }
            }
        }
        if(indexSelector != INT_MAX)
        {
            retVal = indexSelector;
        }
        return retVal;
    }
};