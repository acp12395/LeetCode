class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>::iterator left = nums.begin();
        vector<int>::iterator right = nums.end() - 1;
        while(!((right == left + 1 || right == left) && (left == nums.begin() || right == nums.end() || (*left <= 0 && *right > 0))))
        {
            vector<int>::iterator m = left + (right - left)/2;
            if(*m <= 0 && *(m + 1) > 0)
            {
                left = m;
                right = m + 1;
            }
            else if(*m <= 0 && *(m + 1) <= 0)
            {
                left = m + 1;
            }
            else if(*m > 0 && *(m + 1) > 0)
            {
                right = m;
            }
        }
        vector<int>::iterator it;
        if(*left > 0)
        {
            it = left;
        }
        else
        {
            it = right;
        }
        int missingPositive = 1;
        while(it < nums.end() - 1)
        {
            if(missingPositive == *it)
            {
                if(*(it + 1) != *it)
                {
                    missingPositive++;
                }
                it++;
            }
            else
            {
                break;
            }
        }
        if(missingPositive == *it)
        {
            missingPositive++;
        }
        return missingPositive;
    }
};