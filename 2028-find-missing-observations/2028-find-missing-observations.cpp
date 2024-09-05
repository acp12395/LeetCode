class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = (rolls.size() + n) * mean;
        int sumN = sum - accumulate(rolls.begin(), rolls.end(), 0);
        vector<int> retVec;
        if(sumN >= n && sumN <= n*6)
        {
            int baseLevel = sumN / n;
            int baseLevelElements = n - sumN % n;
            retVec.insert(retVec.end(), baseLevelElements, baseLevel);
            retVec.insert(retVec.end(), n - baseLevelElements, baseLevel + 1);
        }
        return retVec;
    }
};