class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int resultNumsIndex = 0;
        for(int num = 1; num < nums.size(); num++)
        {
            if(nums[num] != nums[resultNumsIndex])
            {
                resultNumsIndex++;
                nums[resultNumsIndex] = nums[num];
            }
        }
        return resultNumsIndex+1;
    }
};