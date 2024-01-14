class Solution {
public:
    bool closeStrings(string word1, string word2) {
        bool areClose = false;
        if(word1.size() == word2.size())
        {
            unordered_map<char,int> charCountMap1;
            unordered_map<char,int> charCountMap2;
            for(auto& character : word1)
            {
                charCountMap1[character]++;
            }
            for(auto& character : word2)
            {
                charCountMap2[character]++;
            }
            unordered_set<char> charSet1;
            unordered_set<char> charSet2;
            for(auto& [character,_] : charCountMap1)
            {
                charSet1.insert(character);
            }
            for(auto& [character,_] : charCountMap2)
            {
                charSet2.insert(character);
            }
            if(charSet1 == charSet2)
            {
                unordered_map<int,int> countCountMap1;
                unordered_map<int,int> countCountMap2;
                for(auto& [_,count] : charCountMap1)
                {
                    countCountMap1[count]++;
                }
                for(auto& [_,count] : charCountMap2)
                {
                    countCountMap2[count]++;
                }
                areClose = (countCountMap1 == countCountMap2);
            }
        }
        return areClose;
    }
};