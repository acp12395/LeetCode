class Solution {
public:
    string largestOddNumber(string num) {
        for(auto&& i = num.rbegin(); i < num.rend(); i++)
        {
            if((*i)%2 == 0)
            {
                num.erase((i+1).base());
            }
            else
            {
                break;
            }
        }
        return num;
    }
};