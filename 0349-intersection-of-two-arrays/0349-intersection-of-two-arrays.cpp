class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> setNums1, setNums2;
        vector<int> intersect;
        for(auto& num : nums1)
        {
            setNums1.insert(num);
        }
        for(auto& num : nums2)
        {
            setNums2.insert(num);
        }
        for(auto& num : setNums1)
        {
            if(setNums2.insert(num).second == false)
            {
                intersect.push_back(num);
            }
        }
        return intersect;
    }
};