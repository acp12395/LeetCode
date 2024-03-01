class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string res;
        bool atLeastOne1 = false;
        for(auto& digit : s)
        {
            if(digit == '0')
            {
                res.push_back('0');
            }
            else
            {
                if(atLeastOne1 == false)
                {
                    atLeastOne1 = true;
                }
                else
                {
                    res.insert(0,1,'1');
                }
            }
        }
        res.push_back('1');
        return res;
    }
};