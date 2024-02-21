class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int retVal = left;
        if(left != right)
        {
            retVal &= right;
            int mask = INT_MAX;
            int rotation = static_cast<int>(log2(right - left));
            mask = mask << rotation + 1;
            retVal &= mask;
        }
        return retVal;
    }
};