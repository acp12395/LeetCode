class Solution {
public:
    string reversePrefix(string word, char ch) {
        string retStr;
        int occurrence = -1;
        stack<int> charStack;
        for(int i = 0; i < word.size(); i++)
        {
            charStack.push(word[i]);
            if(word[i] == ch)
            {
                occurrence = i;
                break;
            }
        }
        if(occurrence >= 0)
        {
            while(!charStack.empty())
            {
                retStr.push_back(charStack.top());
                charStack.pop();
            }
            retStr.append(word.substr(occurrence + 1));
        }
        else
        {
            retStr = word;
        }
        return retStr;
    }
};