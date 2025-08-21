/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long low = 1;
        long high = INT_MAX;
        int mid;
        int retVal;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(guess(mid) < 0)
            {
                high = mid - 1;
            }
            else if(guess(mid) == 0)
            {
                retVal = mid;
                break;
            }
            else 
            {
                low = mid + 1;   
            }
        }
        return retVal;
    }
};