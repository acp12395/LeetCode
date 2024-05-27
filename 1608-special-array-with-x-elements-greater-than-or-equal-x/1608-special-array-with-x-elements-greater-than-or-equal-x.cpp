class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = -1;
        int prevNum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= nums.size() - i && nums.size() - i > prevNum)
            {
                x = nums.size() - i;
                break;
            }
            prevNum = nums[i];
        }
        return x;
    }
};