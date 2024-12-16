class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i = 0; i < k; i++)
        {
            int min = INT_MAX;
            int indexToChange;
            for(int index = 0; index < nums.size(); index++)
            {
                if(min > nums[index])
                {
                    min = nums[index];
                    indexToChange = index;
                }
            }
            nums[indexToChange] = nums[indexToChange] * multiplier;
        }
        return nums;
    }
};