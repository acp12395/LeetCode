class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> xorVec;
        xorVec.push_back(0);
        int sum = 0;
        for(auto& num : nums)
        {
            int xorTill = xorVec.size();
            for(int index = 0; index < xorTill; index++)
            {
                int xorResult = xorVec[index]^num;
                sum += xorResult;
                xorVec.push_back(xorResult);
            }
        }
        return sum;
    }
};