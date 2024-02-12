class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutiveOnes = 0;
        int count = 0;
        for(auto& num : nums)
        {
            if(num == 1)
            {
                count++;
                if(count > maxConsecutiveOnes)
                {
                    maxConsecutiveOnes = count;
                }
            }
            else
            {
                count = 0;
            }
        }
        return maxConsecutiveOnes;
    }
};