class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for(auto character = s.rbegin(); character < s.rend(); character++)
        {
            if(*character != ' ')
            {
                length++;
            }
            else if(length != 0)
            {
                break;
            }
        }
        return length;
    }
};