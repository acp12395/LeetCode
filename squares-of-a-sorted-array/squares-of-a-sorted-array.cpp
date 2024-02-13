class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> retVec = nums;
        for(auto& num : retVec)
        {
            num = num*num;
        }
        sort(retVec.begin(), retVec.end());
        return retVec;
    }
};