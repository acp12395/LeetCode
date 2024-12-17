class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> charCountMap;
        string retString;
        for(auto& character : s)
        {
            charCountMap[character]++;
        }
        stack<char> charStack;
        for(auto& [character,_] : charCountMap)
        {
            charStack.push(character);
        }
        char upperBound, lowerBound;
        bool goingUp = false;
        upperBound = charStack.top();
        charStack.pop();
        bool upperEqualsLower = false;
        if(charStack.size() > 0)
        {
            lowerBound = charStack.top();
            charStack.pop();
        }
        else
        {
            lowerBound = upperBound;
            upperEqualsLower = true;
        }
        while(charCountMap.size() > 0)
        {
            if(!goingUp)
            {
                if(charCountMap[upperBound] > repeatLimit)
                {
                    retString.append(repeatLimit, upperBound);
                    charCountMap[upperBound] -= repeatLimit;
                    goingUp = true;
                }
                else
                {
                    retString.append(charCountMap[upperBound], upperBound);
                    charCountMap.erase(upperBound);
                    upperBound = lowerBound;
                    if(charStack.size() > 0)
                    {
                        lowerBound = charStack.top();
                        charStack.pop();
                    }
                }
            }
            else
            {
                retString.append(1, lowerBound);
                if(charCountMap[lowerBound] == 1)
                {
                    charCountMap.erase(lowerBound);
                    if(charStack.size() > 0)
                    {
                        lowerBound = charStack.top();
                        charStack.pop();
                    }
                    else
                    {
                        lowerBound = upperBound;
                    }
                }
                else
                {
                    charCountMap[lowerBound]--;
                }
                goingUp = false;
            }
            if(upperBound == lowerBound)
            {
                if(upperEqualsLower)
                {
                    break;
                }
                else
                {
                    upperEqualsLower = true;
                }
            }
            else
            {
                upperEqualsLower = false;
            }
        }
        return retString;
    }
};