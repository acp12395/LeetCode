class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int retNum = -1;
        vector<int> numbers = nums;
        sort(numbers.begin(), numbers.end());
        for(auto& number : numbers)
        {
            if(number != ++retNum)
            {
                break;
            }
            else if(retNum == numbers[numbers.size() - 1])
            {
                retNum++;
            }
        }
        return retNum;
    }
};