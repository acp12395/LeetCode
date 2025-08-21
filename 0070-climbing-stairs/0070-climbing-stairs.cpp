class Solution {
private:
    map<int, int> stepsWaysMap;
public:
    int climbStairs(int n) {
        if(n == 1)
        {
            return 1;
        }
        else if(n == 2)
        {
            return 2;
        }
        else
        {
            if(stepsWaysMap.count(n) == 1)
            {
                return stepsWaysMap[n];
            }
            stepsWaysMap[n] = (climbStairs(n - 2)) + (climbStairs(n - 1));
            return stepsWaysMap[n];
        }
    }
};