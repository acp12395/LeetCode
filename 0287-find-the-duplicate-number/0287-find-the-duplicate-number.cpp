class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate;
        vector<int> numCount(nums.size(),0);
        for(auto& num : nums)
        {
            if(++numCount[num] == 2)
            {
                duplicate = num;
                break;
            }
        }
        return duplicate;
    }
};