class Solution {
public:
    int longestValidParentheses(string s) {
        int longestSubstringSize = 0;
        int counter = 1;
        int parenthesesLevel = 0;
        int substringComparator;
        unordered_map<int,int> substringStart;
        for(auto& parentheses : s)
        {
            if(parentheses == '(')
            {
                parenthesesLevel++;
                if(substringStart.count(parenthesesLevel) == 0)
                {
                    substringStart[parenthesesLevel] = counter;
                }
            }
            else
            {
                substringStart.erase(parenthesesLevel + 1);
                if(substringStart.count(parenthesesLevel) != 0)
                {
                    substringComparator = (counter - substringStart[parenthesesLevel] + 1);
                    if(longestSubstringSize < substringComparator)
                    {
                        longestSubstringSize = substringComparator;
                    }
                }
                parenthesesLevel--;
            }
            counter++;
        }
        return longestSubstringSize;
    }
};