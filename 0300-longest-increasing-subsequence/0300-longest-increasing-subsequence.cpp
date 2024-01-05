class Solution {
private:
    int lengthOfLISHelper(vector<int>& nums,int index, unordered_map<int,int>& resultMap)
    {
        if(resultMap.count(index))
        {
            return resultMap[index];
        }
        int l_index = index;
        resultMap[l_index] = 1;
        int partialResult;
        for(;index < nums.size();++index)
        {
            if(nums[index]>nums[l_index])
            {
                partialResult = (lengthOfLISHelper(nums,index,resultMap)+1);
                if(partialResult > resultMap[l_index])
                {
                    resultMap[l_index] = partialResult;
                }
            }
        }
        return resultMap[l_index];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int retVal = 0;
        int res;
        int numIndex = 0;
        unordered_map<int,int> lengthsMap;
        while(numIndex < nums.size())
        {
            res = lengthOfLISHelper(nums,numIndex,lengthsMap);
            retVal = (res>retVal) ? res : retVal;
            numIndex++;
        }
        return retVal;
    }
};