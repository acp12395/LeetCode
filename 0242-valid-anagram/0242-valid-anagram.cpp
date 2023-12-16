class Solution {
public:
    bool isAnagram(string s, string t) {
        bool retVal = false;
        if(s.size() == t.size())
        {
            unordered_map<char,int> charAppearings;
            for(auto& firstStringChars : s)
            {
                charAppearings[firstStringChars]++;
            }
            for(auto& secondStringChars : t)
            {
                if((--charAppearings[secondStringChars]) == 0)
                {
                    charAppearings.erase(secondStringChars);
                }
            }
            if(charAppearings.empty())
            {
                retVal = true;
            }
        }
        return retVal;
    }
};