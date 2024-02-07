class Solution {
public:
    string frequencySort(string s) {
        string frequencyStr(s.size(),0);
        unordered_map<char, int> charCountMap;
        for(auto& character : s)
        {
            charCountMap[character]++;
        }
        map<int, vector<char>> frequencyCharactersMap;
        for(auto& [character, count] : charCountMap)
        {
            if(frequencyCharactersMap.count(count) == 0)
            {
                vector<char> vec;
                frequencyCharactersMap[count] = vec;
            }
            frequencyCharactersMap[count].push_back(character);
        }
        int rStart, rEnd = s.size();
        for(auto& [frequency,charVec] : frequencyCharactersMap)
        {
            for(auto& character : charVec)
            {
                rStart = rEnd - 1;
                rEnd -= frequency;
                for(int charIndex = rStart; charIndex >= rEnd; charIndex--)
                {
                    frequencyStr[charIndex] = character;
                }
            }
        }
        return frequencyStr;
    }
};