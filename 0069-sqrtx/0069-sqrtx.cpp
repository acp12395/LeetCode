class Solution {
public:
    int mySqrt(int x) {
        long square;
        long low = 0;
        long high = INT_MAX;
        long mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(mid * mid == x)
            {
                return mid;
            }
            else if(mid * mid < x)
            {
                low = mid + 1;
            }
            else if(mid * mid > x)
            {
                high = mid - 1;
            }
        }
        if(mid * mid > x)
        {
            mid--;
        }
        return mid;
    }
};