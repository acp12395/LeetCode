class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> retVec;
        unordered_map<int,int> intExistenceMap;
        int vecSize = 0;
        for(auto& num : nums)
        {
            intExistenceMap[num]++;
            if(intExistenceMap[num] > vecSize)
            {
                vecSize = intExistenceMap[num];
            }
        }
        retVec.resize(vecSize);
        for(auto& intCountPair : intExistenceMap)
        {
            for(int i = 0; i < intCountPair.second; i++)
            {
                retVec[i].push_back(intCountPair.first);
            }
        }
        return retVec;
    }
};