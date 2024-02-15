class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] == nums[i + 1])
            {
                for(int j = i + 1; j < size; j++)
                {
                    nums[j - 1] = nums[j];
                }
                size--;
            }
        }
        return size;
    }
};