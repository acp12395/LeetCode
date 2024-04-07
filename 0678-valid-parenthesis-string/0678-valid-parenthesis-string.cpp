class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack, asterStack;
        for(int charIndex = 0; charIndex < s.size(); charIndex++)
        {
            if(s[charIndex] == '(')
            {
                openStack.push(charIndex);
            }
            else if(s[charIndex] == '*')
            {
                asterStack.push(charIndex);
            }
            else
            {
                if(!openStack.empty())
                {
                    openStack.pop();
                }
                else if(!asterStack.empty())
                {
                    asterStack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        while(!(openStack.empty() && asterStack.empty()))
        {
            if(!openStack.empty())
            {
                if(!asterStack.empty())
                {
                    if(openStack.top() > asterStack.top())
                    {
                        return false;
                    }
                    else
                    {
                        openStack.pop();
                        asterStack.pop();
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return true;
            }
        }
        return true;
    }
};