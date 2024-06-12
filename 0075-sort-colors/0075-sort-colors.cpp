class Solution {
public:
    void sortColors(vector<int>& nums) {
        int iNextRed = 0, iNextBlue = nums.size() - 1;
        int index = 0;
        while(index <= iNextBlue)
        {
            if(nums[index] == 0)
            {
                swap(nums[index], nums[iNextRed]);
                index = index == iNextRed ? index + 1 : index;
                iNextRed++;
            }
            else if(nums[index] == 1)
            {
                index++;
            }
            else
            {
                swap(nums[index], nums[iNextBlue]);
                iNextBlue--;
            }
        }
    }
};