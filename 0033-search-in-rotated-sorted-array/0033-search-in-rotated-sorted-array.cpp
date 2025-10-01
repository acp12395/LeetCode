class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int rotated = 0;
        int retVal = -1;
        if(nums.size() >= 2)
        {
            while(low <= high)
            {
                mid = (low + high) / 2;
                if(mid < nums.size() - 1)
                {
                    if(nums[mid] > nums[0] && nums[mid + 1] > nums[0])
                    {
                        low = mid + 1;
                    }
                    else if(nums[mid] > nums[0] && nums[mid + 1] < nums[0])
                    {
                        rotated = (nums.size() - 1) - mid;
                        break;
                    }
                    else if(nums[mid] < nums[0] && nums[mid + 1] < nums[0])
                    {
                        high = mid - 1;
                    }
                }
            }
            low = (0 + (nums.size() - rotated)) % nums.size();
            high = (nums.size() - 1 + (nums.size() - rotated)) % nums.size();
            while((low + rotated) % nums.size() <= (high + rotated) % nums.size())
            {
                mid = ((((low + rotated) % nums.size() + (high + rotated) % nums.size()) / 2) + (nums.size() - rotated)) % nums.size();
                if(nums[mid] == target) 
                {
                    retVal = mid;
                    break;
                }
                else if(nums[mid] < target) 
                {
                    low = (mid + 1 + nums.size()) % nums.size();
                }
                else
                {
                    high = (mid - 1 + nums.size()) % nums.size();
                }
            }
        }
        else
        {
            if(nums[0] == target)
            {
                retVal = 0;
            }
        }
        return retVal;
    }
};