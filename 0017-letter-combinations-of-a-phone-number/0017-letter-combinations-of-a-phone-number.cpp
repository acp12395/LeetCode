class Solution {
    map<char,string> lettersForNumber{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

public:
    vector<string> letterCombinations(string digits) {
        vector<string> retVec;
        if(!digits.empty())
        {
            char singleDigit = digits[0];
            string singleDigitLetters = lettersForNumber.at(singleDigit);
            vector<string> subStringOfDigitsRetVec(1);
            digits.erase(0,1);
            if(!digits.empty())
            {
                subStringOfDigitsRetVec = letterCombinations(digits);
            }

            for(auto& letters : singleDigitLetters)
            {
                for(auto& strings : subStringOfDigitsRetVec)
                {
                    string s;
                    s.push_back(letters);
                    s.append(strings);
                    retVec.push_back(s);
                }
            }
        }
        return retVec;
    }
};