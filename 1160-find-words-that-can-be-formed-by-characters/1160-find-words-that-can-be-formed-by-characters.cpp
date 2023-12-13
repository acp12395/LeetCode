class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int retVal = 0;
        for(auto& i : words)
        {
            string charsCpy = chars;
            int charCounter = 0;
            for(auto& j : i)
            {
                auto&& charFoundAt = charsCpy.find(j);
                if(charFoundAt != string::npos)
                {
                    charsCpy.erase(charFoundAt, 1);
                    charCounter++;
                }
                else
                {
                    break;
                }
            }
            if(charCounter == i.size())
            {
                retVal += charCounter;
            }
        }
        return retVal;
    }
};