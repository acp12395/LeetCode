class Solution {
public:
    string largestGoodInteger(string num) {
        string retVal = "";
        int digitStorage = -1;
        int previousDigit = -1;
        int sameDigitCounter = 0;
        for(auto& i : num)
        {
            int currentDigit = static_cast<int>(i) - static_cast<int>('0');
            if(previousDigit == currentDigit)
            {
                if(digitStorage != currentDigit)
                {
                    sameDigitCounter++;
                    if(sameDigitCounter >= 3)
                    {
                        if(previousDigit > digitStorage)
                        {
                            digitStorage = previousDigit;
                        }
                    }
                }
            }
            else
            {
                sameDigitCounter = 1;
                previousDigit = currentDigit;
            }
        }
        if(digitStorage >= 0)
        {
            retVal.push_back(static_cast<char>(digitStorage + static_cast<int>('0')));
            retVal.push_back(static_cast<char>(digitStorage + static_cast<int>('0')));
            retVal.push_back(static_cast<char>(digitStorage + static_cast<int>('0')));
        }
        return retVal;
    }
};