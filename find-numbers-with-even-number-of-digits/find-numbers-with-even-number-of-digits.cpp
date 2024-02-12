class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int retVal = 0;
        for(auto& num : nums)
        {
            for(int x = 5; x >= 0; x--)
            {
                if(num/pow(10,x) >= 1)
                {
                    if((x+1)%2 == 0)
                    {
                        retVal++;
                    }
                    break;
                }
            }
        }
        return retVal;
    }
};