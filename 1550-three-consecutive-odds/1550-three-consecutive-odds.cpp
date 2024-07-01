class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCounter = 0;
        for(auto& num : arr)
        {
            if(num%2 == 1)
            {
                if(++oddCounter == 3)
                {
                    break;
                }
            }
            else
            {
                oddCounter = 0;
            }
        }
        return oddCounter == 3 ? true : false;
    }
};