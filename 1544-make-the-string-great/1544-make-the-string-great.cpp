class Solution {
public:
    string makeGood(string s) {
        stack<char> charStack;
        for(int charIndex = 0; charIndex < s.size(); charIndex++)
        {
            if(!charStack.empty() && (s[charIndex] == charStack.top() + 32 || s[charIndex] == charStack.top() - 32))
            {
                charStack.pop();
                s.erase(charIndex - 1, 2);
                charIndex = charIndex - 2;
            }
            else
            {
                charStack.push(s[charIndex]);
            }
        }
        return s;
    }
};