class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mPtr = 0, nPtr = 0;
        for(; nPtr < n; mPtr++)
        {
            if(nums1[mPtr] > nums2[nPtr] || mPtr >= m)
            {
                for(int i = nums1.size() - 1; i > mPtr; i--)
                {
                    nums1[i] = nums1[i - 1];
                }
                nums1[mPtr] = nums2[nPtr];
                nPtr++;
                m++;
            }
        }
    }
};