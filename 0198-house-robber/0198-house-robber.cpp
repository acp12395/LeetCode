class Solution {
private:
    int robHelper(vector<int>& nums, int index, unordered_map<int, int>& indexMaxQtyMap)
    {
        int retVal;
        if(index < 0)
        {
            retVal = 0;
        }
        else
        {
            if(indexMaxQtyMap.count(index) == 1)
            {
                retVal = indexMaxQtyMap[index];
            }
            else
            {
                int numAtIndex = 0;
                if(index < nums.size())
                {
                    numAtIndex = nums[index];
                }
                indexMaxQtyMap[index] = max(robHelper(nums, index - 2, indexMaxQtyMap) + numAtIndex, robHelper(nums, index - 1, indexMaxQtyMap));
                retVal = indexMaxQtyMap[index];
            }
        }
        return retVal;
    }
public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> indexMaxQtyMap;
        return robHelper(nums, nums.size(), indexMaxQtyMap);
    }
};