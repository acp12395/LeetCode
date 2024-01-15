class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> winnersLossesVec(2);
        unordered_map<int,int> lossesCountMap;
        {
            int createZeroCount;
            for(auto& match : matches)
            {
                createZeroCount = lossesCountMap[match[0]];
                lossesCountMap[match[1]]++;
            }
        }
        for(auto& lossesCount : lossesCountMap)
        {
            if(lossesCount.second == 1)
            {
                winnersLossesVec[1].push_back(lossesCount.first);
            }
            else if(lossesCount.second == 0)
            {
                winnersLossesVec[0].push_back(lossesCount.first);
            }
        }
        sort(winnersLossesVec[0].begin(), winnersLossesVec[0].end());
        sort(winnersLossesVec[1].begin(), winnersLossesVec[1].end());
        return winnersLossesVec;
    }
};