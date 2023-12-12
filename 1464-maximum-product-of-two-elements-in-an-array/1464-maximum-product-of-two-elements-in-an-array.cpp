class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int retVal;
        vector<int> numsCpy = nums;
        int max1, max2;
        auto&& maxIt = max_element(numsCpy.begin(), numsCpy.end());
        max1 = *maxIt;
        numsCpy.erase(maxIt);
        maxIt = max_element(numsCpy.begin(), numsCpy.end());
        max2 = *maxIt;
        retVal = (max1-1)*(max2-1);
        return retVal;
    }
};