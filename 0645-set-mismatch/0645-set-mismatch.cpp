class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> errorNums(2);
        unordered_map<int,int> numCount;
        for(auto& num : nums)
        {
            numCount[num]++;
        }
        for(int num = 1; num < nums.size()+1; num++)
        {
            if(numCount[num] == 2)
            {
                errorNums[0] = num;
            }
            else if(numCount[num] == 0)
            {
                errorNums[1] = num;
            }
        }
        return errorNums;
    }
};