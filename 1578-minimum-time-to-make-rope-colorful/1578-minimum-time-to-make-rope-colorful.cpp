class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int retVal = 0;
        int comparatorIndex = 0;
        if(colors.size() == neededTime.size())
        {
            for(int color = 1; color <= (colors.size()); color++)
            {
                if(colors[comparatorIndex] == colors[color])
                {
                    if(neededTime[comparatorIndex] < neededTime[color])
                    {
                        retVal += neededTime[comparatorIndex];
                        comparatorIndex = color;
                    }
                    else
                    {
                        retVal += neededTime[color];
                    }
                }
                else
                {
                    comparatorIndex = color;
                }
            }
        }
        return retVal;
    }
};