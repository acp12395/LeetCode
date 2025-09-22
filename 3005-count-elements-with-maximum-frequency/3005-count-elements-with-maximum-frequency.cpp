class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> numFreqMap;
        for(auto& num : nums)
        {
            numFreqMap[num]++;
        }
        unordered_set<int> maxFreqElements;
        int maxFreq = 0;
        for(auto& [num,freq] : numFreqMap)
        {
            if(freq > maxFreq)
            {
                maxFreq = freq;
                maxFreqElements.clear();
            }
            if(freq == maxFreq)
            {
                maxFreqElements.insert(num);
            }
        }
        return maxFreq*maxFreqElements.size();
    }
};