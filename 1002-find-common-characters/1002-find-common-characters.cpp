class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<unordered_map<char,int>> charCounts;
        for(auto& word : words)
        {
            unordered_map<char,int> charCountMap;
            for(auto& character : word)
            {
                charCountMap[character]++;
            }
            charCounts.push_back(charCountMap);
        }
        vector<string> comChars;
        for(char character = 'a'; character <= 'z'; character++)
        {
            int commonCount = INT_MAX;
            for(auto& count : charCounts)
            {
                commonCount = commonCount > count[character] ? count[character] : commonCount;
            }
            string inputCharStr;
            inputCharStr.push_back(character);
            for(; commonCount > 0; commonCount--)
            {
                comChars.push_back(inputCharStr);
            }
        }
        return comChars;
    }
};