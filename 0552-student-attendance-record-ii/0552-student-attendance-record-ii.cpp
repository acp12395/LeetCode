class Solution {
private:
    vector<vector<vector<int>>> memo;
    int checkRecordHelper(int n, int absents, int consecutiveDelays)
    {
        int recordSum = 0;
        if(absents >= 2 || consecutiveDelays >= 3)
        {
            return 0;
        }
        else if(memo[n][absents][consecutiveDelays] != -1)
        {
            return memo[n][absents][consecutiveDelays];
        }
        else if(n == 0)
        {
            return 1;
        }
        else
        {
            recordSum = (checkRecordHelper(n - 1, absents + 1, 0) + recordSum)%1000000007;
            recordSum = (checkRecordHelper(n - 1, absents, consecutiveDelays + 1) + recordSum)%1000000007;
            recordSum = (checkRecordHelper(n - 1, absents, 0) + recordSum)%1000000007;
        }
        memo[n][absents][consecutiveDelays] = recordSum;
        return recordSum;
    }
public:
    int checkRecord(int n) {
        memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return checkRecordHelper(n, 0, 0);
    }
};