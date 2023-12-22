class Solution {
public:
    int maxScore(string s) {
        int retScore = 0;
        vector<int> zeros(s.size()-1);
        int count = 0;
        int sum = 0;
        for(int leftToRightIt = 0; leftToRightIt < s.size()-1; leftToRightIt++)
        {
            if((s[leftToRightIt]-'0') == 0)
            {
                count++;
            }
            zeros[leftToRightIt] = count;
        }
        count = 0;
        for(int rightToLeftIt = s.size()-1; rightToLeftIt > 0; rightToLeftIt--)
        {
            if((s[rightToLeftIt]-'0') == 1)
            {
                count++;
            }
            sum = count + zeros[rightToLeftIt-1];
            if(sum > retScore)
            {
                retScore = sum;
            }
        }
        return retScore;
    }
};