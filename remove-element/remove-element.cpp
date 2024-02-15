class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(nums[i] == val)
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