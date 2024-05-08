class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int> scoreRankMap;
        {
            vector<int> sortedScores = score;
            sort(sortedScores.begin(), sortedScores.end(), greater<int>());
            for(int i = 0; i < sortedScores.size(); i++)
            {
                scoreRankMap[sortedScores[i]] = i + 1;
            }
        }
        vector<string> ranks;
        for(auto& scr : score)
        {
            if(scoreRankMap[scr] == 1)
            {
                ranks.push_back("Gold Medal");
            }
            else if(scoreRankMap[scr] == 2)
            {
                ranks.push_back("Silver Medal");
            }
            else if(scoreRankMap[scr] == 3)
            {
                ranks.push_back("Bronze Medal");
            }
            else
            {
                ranks.push_back(to_string(scoreRankMap[scr]));
            }
        }
        return ranks;
    }
};