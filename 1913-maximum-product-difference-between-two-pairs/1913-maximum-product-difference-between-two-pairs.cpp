class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int retVal;
        array<int,2> lowest = {INT_MAX, INT_MAX};
        array<int,2> highest = {0,0};
        for(auto& num : nums)
        {
            if(num < lowest[0])
            {
                if(lowest[0] < lowest[1])
                {
                    lowest[1] = lowest[0];
                }
                lowest[0] = num;
            }
            else if(num < lowest[1])
            {
                if(lowest[1] < lowest[0])
                {
                    lowest[0] = lowest[1];
                }
                lowest[1] = num;
            }
            if(num > highest[0])
            {
                if(highest[0] > highest[1])
                {
                    highest[1] = highest[0];
                }
                highest[0] = num;
            }
            else if(num > highest[1])
            {
                if(highest[1] > highest[0])
                {
                    highest[0] = highest[1];
                }
                highest[1] = num;
            }
        }
        retVal = (highest[1]*highest[0]) - (lowest[1]*lowest[0]);
        return retVal;
    }
};