class Solution {
public:
    int reverse(long x) {
        int retVal=0;
        map<bool,vector<int>> limVectors;
        limVectors[true] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8}; // Pos 0 MSB
        limVectors[false] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};// Pos 0 MSB
        enum class comparisonLevels {same, under, above, beyondLimit};
        comparisonLevels limsComparison = comparisonLevels::same;
        bool sign = (x<0);
        unsigned int absDigit;
        bool isUnitDigitAssigned = false;
        int digitCount = 0;

        for(int index = 9; index>=0; index--)
        {
            int divisor=pow(10,index);
            int digit;
            int digitMultiplier = sign? -1 : 1;
            digit=x/divisor;
            digit=digit%10;
            absDigit=abs(digit);
            if(absDigit != 0)
            {
                isUnitDigitAssigned = true;
            }
            if(isUnitDigitAssigned)
            {
                digitCount++;
                switch(limsComparison)
                {
                    case comparisonLevels::same:
                    {
                        if(absDigit > limVectors[sign].at(9-(digitCount-1)))
                        {
                            if(digitCount==10)
                            {
                                limsComparison = comparisonLevels::beyondLimit;
                            }
                            else
                            {
                                limsComparison = comparisonLevels::above;
                            }
                        }
                        else if(absDigit < limVectors[sign].at(9-(digitCount-1)))
                        {
                            limsComparison = comparisonLevels::under;
                        }
                        else
                        {
                        }
                        break;
                    }
                    case comparisonLevels::under:
                    {
                        if(absDigit > limVectors[sign].at(9-(digitCount-1)))
                        {
                            if(digitCount==10)
                            {
                                limsComparison = comparisonLevels::beyondLimit;
                            }
                            else
                            {
                                limsComparison = comparisonLevels::above;
                            }
                        }
                        else
                        {
                        }
                        break;
                    }
                    case comparisonLevels::above:
                    {
                        if(absDigit < limVectors[sign].at(9-(digitCount-1)))
                        {
                            limsComparison = comparisonLevels::under;
                        }
                        else if(digitCount == 10)
                        {
                            limsComparison = comparisonLevels::beyondLimit;
                        }
                        else
                        {
                        }
                        break;
                    }
                }
                digitMultiplier *= pow(10,digitCount-1);
                retVal = retVal+absDigit*digitMultiplier;
                if(limsComparison == comparisonLevels::beyondLimit)
                {
                    retVal = 0;
                    break;
                }
            }
        }
        x = retVal;
        return x;
    }
};