class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> rearrangedArray;
        int negativesPtr = 0, positivesPtr = 0;
        while(rearrangedArray.size() < nums.size())
        {
            for(; positivesPtr < nums.size(); positivesPtr++)
            {
                if(nums[positivesPtr] > 0)
                {
                    rearrangedArray.push_back(nums[positivesPtr]);
                    positivesPtr++;
                    break;
                }
            }
            for(; negativesPtr < nums.size(); negativesPtr++)
            {
                if(nums[negativesPtr] < 0)
                {
                    rearrangedArray.push_back(nums[negativesPtr]);
                    negativesPtr++;
                    break;
                }
            }
        }
        return rearrangedArray;
    }
};