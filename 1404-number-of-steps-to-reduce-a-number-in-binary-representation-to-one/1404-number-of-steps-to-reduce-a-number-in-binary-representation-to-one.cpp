class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        if(s.size() != 1)
        {
            bool oneReached = false;
            int ones = 0, zeros = 0;
            for(int bitIndex = s.size() - 1; bitIndex > 0; bitIndex--)
            {
                if(s[bitIndex] == '0')
                {
                    zeros++;
                    if(ones != 0)
                    {
                        steps += ones;
                        steps++;
                        ones = 0;
                    }
                }
                else if(s[bitIndex] == '1')
                {
                    ones++;
                    if(zeros != 0)
                    {
                        if(oneReached)
                        {
                            steps += zeros * 2 - 2;
                            ones++;
                        }
                        else
                        {
                            steps += zeros;
                        }
                        zeros= 0;
                    }
                    oneReached = true;
                }
            }
            if(ones > 0)
            {
                steps += ones;
                steps += 2;
            }
            else if(zeros > 0)
            {
                if(oneReached)
                {
                    steps += zeros * 2;
                    steps++;
                }
                else
                {
                    steps += zeros;
                }
            }
        }
        return steps;
    }
};