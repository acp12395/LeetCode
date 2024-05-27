class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> emptyVec;
        subs.push_back(emptyVec);
        for(auto& num : nums)
        {
            int insertTill = subs.size();
            for(int index = 0; index < insertTill; index++)
            {
                subs.push_back(subs[index]);
                subs[subs.size()-1].push_back(num);
            }
        }
        return subs;
    }
};