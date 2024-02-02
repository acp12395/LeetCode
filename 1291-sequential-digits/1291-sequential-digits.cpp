class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int power, firstDigit, addNum;
        bool trespassed = false;
        vector<int> retVec;
        for(power = 9; power >= 1; power--)
        {
            firstDigit = low/pow(10,power);
            if(firstDigit > 0)
            {
                break;
            }
        }
        for(; !(trespassed) && power <= 9; power++)
        {
            for(int digit = 1; digit <= 9; digit++)
            {
                if(digit <= 10 - power - 1)
                {
                    addNum = 0;
                    for(int digitIndex = 0; digitIndex <= power; digitIndex++)
                    {
                        addNum += (digit + digitIndex) * pow(10, power - digitIndex);
                    }
                    if(addNum >= low)
                    {
                        if(addNum <= high)
                        {
                            retVec.push_back(addNum);
                        }
                        else
                        {
                            trespassed = true;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return retVec;
    }
};