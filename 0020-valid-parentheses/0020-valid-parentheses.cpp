class Solution {
public:
    bool isValid(string s) {
        bool retVal = false;
        string openingBrackets;
        char open;
        char close;
        int countOpen = 0, countClose = 0;
        for(auto& bracket : s)
        {
            if(bracket=='('||bracket=='{'||bracket=='[')
            {
                countOpen++;
                openingBrackets.push_back(bracket);
            }
            else
            {
                countClose++;
                if(!openingBrackets.empty())
                {
                    open = openingBrackets[openingBrackets.length()-1];
                    openingBrackets.pop_back();
                    if((open == '(' && bracket != ')') || (open == '{' && bracket != '}') || (open == '[' && bracket != ']') )
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }

        if(countOpen == countClose)
        {
            retVal = true;
        }

        return retVal;
    }
};