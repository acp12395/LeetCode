class Solution {
public:
    int minOperations(vector<int>& nums) {
        int retVal = 0;
        unordered_map<int,int> countMap;
        for(auto& num : nums)
        {
            countMap[num]++;
        }
        for(auto& count : countMap)
        {
            if(count.second%3 == 0)
            {
                retVal += count.second/3;
            }
            else
            {
                if(count.second == 1)
                {
                    retVal = -1;
                    break;
                }
                else
                {
                    retVal += count.second/3 + 1;
                }
            }
        }
        return retVal;
    }
};