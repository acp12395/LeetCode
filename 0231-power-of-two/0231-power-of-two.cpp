class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool retVal = false;
        if(n > 0)
        {
            retVal = (floor(log2(n)) == log2(n)) ? 1 : 0;
        }
        return retVal;
    }
};