// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long low = 1;
        long high = n;
        int mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(isBadVersion(mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if(!isBadVersion(mid))
        {
            mid++;
        }
        return mid;
    }
};