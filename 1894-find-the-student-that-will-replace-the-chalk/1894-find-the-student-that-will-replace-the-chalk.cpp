class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        for(auto& chalkAtIndex : chalk)
        {
            sum += chalkAtIndex;
            if(sum > k)
            {
                break;
            }
        }
        k = k % sum;
        int res = 0;
        for(; res < chalk.size(); res++)
        {
            if(k < chalk[res])
            {
                break;
            }
            k -= chalk[res];
        }
        return res;
    }
};