class Solution {
public:
    int strStr(string haystack, string needle) {
        int occ = -1;
        for(int charHay = 0; charHay < haystack.size(); charHay++)
        {
            if(haystack[charHay] == needle[0] && (haystack.size()-charHay >= needle.size()))
            {
                bool areEqual = true;
                for(int charNeedle = 0; charNeedle < needle.size(); charNeedle++)
                {
                    if(needle[charNeedle] != haystack[charHay+charNeedle])
                    {
                        areEqual = false;
                        break;
                    }
                }
                if(areEqual == true)
                {
                    occ = charHay;
                    break;
                }
            }
        }
        return occ;
    }
};