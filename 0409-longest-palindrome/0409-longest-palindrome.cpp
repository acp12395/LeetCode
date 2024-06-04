class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charCountMap;
        for(auto& character : s)
        {
            charCountMap[character]++;
        }
        int length = 0;
        bool oddFound = false;
        for(auto& [_, count] : charCountMap)
        {
            if(count%2 == 1)
            {
                length--;
                oddFound = true;
            }
            length += count;
        }
        return oddFound ? length + 1 : length;
    }
};