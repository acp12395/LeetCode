class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> l_nums = nums;
        sort(l_nums.begin(), l_nums.end());
        int left = 0, right = l_nums.size() - 1;
        while(l_nums[left] < 0 && l_nums[right] > 0)
        {
            if(l_nums[left]*(-1) == l_nums[right])
            {
                break;
            }
            else if(l_nums[left]*(-1) > l_nums[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return (l_nums[left] >= 0 || l_nums[right] <= 0) ? -1 : l_nums[right];
    }
};