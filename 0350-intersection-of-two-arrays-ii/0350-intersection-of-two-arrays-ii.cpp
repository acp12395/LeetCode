class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> numCount;
        vector<int>* smallVec;
        vector<int>* largeVec;
        smallVec = nums1.size() < nums2.size() ? &nums1 : &nums2;
        for(auto num : *smallVec)
        {
            numCount[num]++;
        }
        largeVec = nums1.size() < nums2.size() ? &nums2 : &nums1;
        vector<int> res;
        for(auto num : *largeVec)
        {
            if(numCount[num] > 0)
            {
                res.push_back(num);
                numCount[num]--;
            }
        }
        return res;
    }
};