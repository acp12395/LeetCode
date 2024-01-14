class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int retVal;
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        int indexDifference;
        bool breaker = false;
        while(!breaker)
        {
            if(target > nums[rightIndex])
            {
                retVal = rightIndex + 1;
                breaker = true;
            }
            else if(target == nums[rightIndex])
            {
                retVal = rightIndex;
                breaker = true;
            }
            else if(target <= nums[leftIndex])
            {
                retVal = leftIndex;
                breaker = true;
            }
            else if(leftIndex == rightIndex)
            {
                retVal = leftIndex;
                breaker = true;
            }
            else
            {
                indexDifference = rightIndex - leftIndex;
                if(target <= nums[leftIndex + indexDifference/2])
                {
                    rightIndex = leftIndex + indexDifference/2;
                }
                else
                {
                    leftIndex = rightIndex - indexDifference/2;
                }
            }
        }
        return retVal;
    }
};