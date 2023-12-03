class Solution {
    map<char,int> equivalentValues{{'I',1}, {'V', 5}, {'X',10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
public:
    int romanToInt(string s) {
        int retVal = 0;
        int lastAddingValue = INT32_MAX;
        int currentDigitValue;
        int sameLetterCounter = 1;
        for(auto& i : s)
        {
            try
            {
                currentDigitValue = equivalentValues.at(i);
            }
            catch(std::out_of_range)
            {
                retVal = -1;
                break;
            }

            if(lastAddingValue > currentDigitValue)
            {
                retVal += currentDigitValue;
                lastAddingValue = currentDigitValue;
                if(lastAddingValue == 5 || lastAddingValue == 50 || lastAddingValue == 500)
                {
                    sameLetterCounter = 3;
                }
                else
                {
                    sameLetterCounter = 1;
                }
            }
            else if(lastAddingValue == currentDigitValue)
            {
                if(sameLetterCounter < 3)
                {
                    sameLetterCounter++;
                    retVal += currentDigitValue;
                    lastAddingValue = currentDigitValue;
                }
                else
                {
                    retVal = -1;
                    break;
                }
            }
            else
            {
                if(lastAddingValue != 0)
                {
                    if(sameLetterCounter < 2)
                    {
                        if(currentDigitValue/10 == lastAddingValue || currentDigitValue/5 == lastAddingValue)
                        {
                            retVal -= 2*lastAddingValue;
                            retVal += currentDigitValue;
                            lastAddingValue = lastAddingValue/2;
                            sameLetterCounter = 0;
                        }
                        else
                        {
                            retVal = -1;
                            break;
                        }
                    }
                    else
                    {
                        retVal = -1;
                        break;
                    }
                }
                else
                {
                    retVal = -1;
                    break;
                }
            }
        }
        return retVal;
    }
};