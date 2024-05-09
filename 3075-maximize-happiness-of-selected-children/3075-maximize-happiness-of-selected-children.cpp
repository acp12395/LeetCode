class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        vector<int> sortedHappiness = happiness;
        sort(sortedHappiness.begin(), sortedHappiness.end(), greater<int>());
        long long maxHappinessSum = 0;
        for(int i = 0; i < k; i++)
        {
            if(sortedHappiness[i] - i > 0)
            {
                maxHappinessSum += sortedHappiness[i] - i;
            }
            else
            {
                break;
            }
        }
        return maxHappinessSum;
    }
};