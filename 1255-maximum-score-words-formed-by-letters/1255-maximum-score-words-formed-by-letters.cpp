class Solution {
private:
    int countMaxScore(vector<string>& words, vector<char>& letters, vector<int>& score, unordered_map<char, int>& letterCountMap, int wordIndex)
    {
        if(wordIndex == words.size())
        {
            return 0;
        }
        else
        {
            int scoreIncludingThis = 0, scoreWithoutThis = 0;
            scoreWithoutThis = countMaxScore(words, letters, score, letterCountMap, wordIndex + 1);
            bool ok = true;
            int charIndex = 0;
            for(; charIndex < words[wordIndex].size(); charIndex++)
            {
                if(--letterCountMap[words[wordIndex][charIndex]] >= 0)
                {
                    scoreIncludingThis += score[words[wordIndex][charIndex] - 'a'];
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                scoreIncludingThis += countMaxScore(words, letters, score, letterCountMap, wordIndex + 1);
            }
            else
            {
                scoreIncludingThis = 0;
            }
            for(; charIndex >= 0; charIndex--)
            {
                letterCountMap[words[wordIndex][charIndex]]++;
            }
            return scoreIncludingThis > scoreWithoutThis ? scoreIncludingThis : scoreWithoutThis;
        }
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int maxScore = 0;
        int index = 0;
        unordered_map<char, int> letterCountMap;
        for(auto& letter : letters)
        {
            letterCountMap[letter]++;
        }
        maxScore = countMaxScore(words, letters, score, letterCountMap, index);
        return maxScore;
    }
};