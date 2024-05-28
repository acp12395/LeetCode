class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLength = 0;
        int leftIndex = 0, rightIndex = -1;
        int cost = 0;
        while(rightIndex < static_cast<int>(s.size() - 1))
        {
            if(cost <= maxCost)
            {
                rightIndex++;
                cost += abs(s[rightIndex] - t[rightIndex]);
                if(cost <= maxCost)
                {
                    int currLength = rightIndex - leftIndex + 1;
                    maxLength = maxLength > currLength ? maxLength : currLength;
                }
            }
            else
            {
                cost -= abs(s[leftIndex] - t[leftIndex]);
                leftIndex++;
                if(leftIndex > rightIndex)
                {
                    rightIndex = leftIndex;
                    cost = abs(s[leftIndex] - t[leftIndex]);
                    if(cost <= maxCost)
                    {
                        int currLength = rightIndex - leftIndex + 1;
                        maxLength = maxLength > currLength ? maxLength : currLength;
                    }
                }
            }
        }
        return maxLength;
    }
};