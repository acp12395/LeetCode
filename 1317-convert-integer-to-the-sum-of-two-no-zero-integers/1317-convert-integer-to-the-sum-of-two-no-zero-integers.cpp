class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> retVec;
        for(int number1 = 1; number1 <= n/2; number1++)
        {
            bool anyZero = false;
            for(int i = 0; i <= 4; i++)
            {
                if(number1/static_cast<int>(pow(10, i)) == 0)
                {
                    if(i == 0)
                    {
                        anyZero = true;
                        break;
                    }
                }
                else
                {
                    int digit = (number1/static_cast<int>(pow(10, i)))%10;
                    if(digit == 0)
                    {
                        anyZero = true;
                        break;
                    }
                }
            }
            if(!anyZero)
            {
                int number2 = n - number1;
                anyZero = false;
                for(int i = 0; i <= 4; i++)
                {
                     if(number2/static_cast<int>(pow(10, i)) == 0)
                    {
                        if(i == 0)
                        {
                            anyZero = true;
                            break;
                        }
                    }
                    else
                    {
                        int digit = (number2/static_cast<int>(pow(10, i)))%10;
                        if(digit == 0)
                        {
                            anyZero = true;
                            break;
                        }
                    }
                }
                if(!anyZero)
                {
                    retVec.push_back(number1);
                    retVec.push_back(number2);
                    break;
                }
            }
        }
        return retVec;
    }
};