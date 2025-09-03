class Solution {
public:
    bool isPerfectSquare(int num) {
        long square;
        long low = 0;
        long high = INT_MAX;
        long mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(mid * mid == num)
            {
                return true;
            }
            else if(mid * mid < num)
            {
                low = mid + 1;
            }
            else if(mid * mid > num)
            {
                high = mid - 1;
            }
        }
        return false;
    }
};