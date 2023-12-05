class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Cpy = nums1;
        vector<int> nums2Cpy = nums2;
        vector<int> result;
        bool gt0Flag = false;
        for(auto& i : nums1)
        {
            if(m == 0)
            {
                result.push_back(nums2Cpy[0]);
                nums2Cpy.erase(nums2Cpy.begin());
                n--;
            }
            else if(n == 0)
            {
                if(!(nums1Cpy[0] == 0 && gt0Flag == true))
                {
                    result.push_back(nums1Cpy[0]);
                    nums1Cpy.erase(nums1Cpy.begin());
                    m--;
                }
            }
            else
            {
                if(gt0Flag && nums1Cpy[0] == 0)
                {
                    result.push_back(nums2Cpy[0]);
                    nums2Cpy.erase(nums2Cpy.begin());
                    n--;
                }
                else
                {
                    if(nums1Cpy[0] < nums2Cpy[0])
                    {
                        result.push_back(nums1Cpy[0]);
                        nums1Cpy.erase(nums1Cpy.begin());
                        m--;
                    }
                    else
                    {
                        result.push_back(nums2Cpy[0]);
                        nums2Cpy.erase(nums2Cpy.begin());
                        n--;
                    }
                    if( *(result.end() - 1) > 0)
                    {
                        gt0Flag = true;
                    }
                }
            }
        }
        nums1 = result;
    }
};