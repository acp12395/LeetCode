class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> elemFreqMap;
        for(auto& num : nums)
        {
            elemFreqMap[num]++;
        }
        pair<int,int> maxFreqCountPair = {0,0};
        for(auto& [_,freq] : elemFreqMap)
        {
            if(freq > maxFreqCountPair.first)
            {
                maxFreqCountPair.first = freq;
                maxFreqCountPair.second = 1;
            }
            else if(freq == maxFreqCountPair.first)
            {
                maxFreqCountPair.second++;
            }
        }
        return maxFreqCountPair.first * maxFreqCountPair.second;
    }
};