class Solution {
private: 
    int deleteAndEarnHelper(vector<int>& numsSet, unordered_map<int, int>& numCountMap, int index, unordered_map<int,int>& numMaxPointMap)
    {
        int retVal = 0;
        if(index == 0)
        {
            numMaxPointMap[numsSet[index]] = numCountMap[numsSet[index]] * numsSet[index];
            retVal = numMaxPointMap[numsSet[index]];
        }
        else if(index > 0)
        {
            if(numMaxPointMap.count(numsSet[index]) == 1)
            {
                retVal = numMaxPointMap[numsSet[index]];
            }
            else if(numsSet[index] - numsSet[index - 1] == 1)
            {
                numMaxPointMap[numsSet[index]] = max(numCountMap[numsSet[index]] * numsSet[index] + deleteAndEarnHelper(numsSet, numCountMap, index - 2, numMaxPointMap), deleteAndEarnHelper(numsSet, numCountMap, index - 1, numMaxPointMap));
            }
            else
            {
                numMaxPointMap[numsSet[index]] = numCountMap[numsSet[index]] * numsSet[index] + deleteAndEarnHelper(numsSet, numCountMap, index - 1, numMaxPointMap);
            }
            retVal = numMaxPointMap[numsSet[index]];
        }
        return retVal;
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> numCountMap;
        for(auto& num : nums)
        {
            numCountMap[num]++;
        }
        vector<int> numsSet;
        for(auto& [num,_] : numCountMap)
        {
            numsSet.push_back(num);
        }
        sort(numsSet.begin(), numsSet.end());
        unordered_map<int,int> numMaxPointMap;
        deleteAndEarnHelper(numsSet, numCountMap, numsSet.size() - 1, numMaxPointMap);
        return numMaxPointMap[numsSet[numsSet.size() - 1]];
    }
};