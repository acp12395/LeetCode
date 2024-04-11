class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> numStack;
        numStack.push(num[0]);
        for(int numIndex = 1; numIndex < num.size(); numIndex++)
        {
            while(!numStack.empty() && num[numIndex] < numStack.top() && k != 0)
            {
                numStack.pop();
                k--;
            }
            numStack.push(num[numIndex]);
        }
        while(k > 0)
        {
            numStack.pop();
            k--;
        }
        string retString(numStack.size(), '*');
        int index = numStack.size() - 1;
        while(numStack.size() > 0)
        {
            retString[index] = numStack.top();
            numStack.pop();
            index--;
        }
        index = 0;
        while(retString[index] == '0')
        {
            index++;
        }
        int strSize = retString.size();
        return (retString.empty() || index == strSize) ? "0" : retString.substr(index, strSize - index);
    }
};