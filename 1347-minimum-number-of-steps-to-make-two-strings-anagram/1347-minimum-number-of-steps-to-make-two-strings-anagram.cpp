class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> charCountMap;
        for(auto& character : s)
        {
            charCountMap[character]++;
        }
        for(auto& character : t)
        {
            charCountMap[character]--;
        }
        int steps = 0;
        for(auto& [_, count] : charCountMap)
        {
            steps += abs(count);
        }
        return steps/2;
    }
};