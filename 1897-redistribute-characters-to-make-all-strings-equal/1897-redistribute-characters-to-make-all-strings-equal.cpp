class Solution {
public:
    bool makeEqual(vector<string>& words) {
        bool retVal = true;
        int vecSize = words.size();
        unordered_map<char,int> countCharsMap;
        for(auto& word : words)
        {
            for(auto& character : word)
            {
                countCharsMap[character]++;
            }
        }
        for(auto& characterCount : countCharsMap)
        {
            if(characterCount.second%vecSize != 0)
            {
                retVal = false;
            }
        }
        return retVal;
    }
};