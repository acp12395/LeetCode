class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        vector<int> numbers = nums;
        sort(numbers.begin(), numbers.end());
        long long retVal = -1, sum = 0;
        for(auto& num : numbers)
        {
            if(num < sum)
            {
                retVal = sum + num;
            }
            sum += num;
        }
        return retVal;
    }
};