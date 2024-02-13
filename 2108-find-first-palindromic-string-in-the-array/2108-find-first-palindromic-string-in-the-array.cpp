class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string retPalindrome;
        for(auto& word : words)
        {
            bool palindromeFlag = true;
            for(int charIndex = 0; charIndex < word.size()/2; charIndex++)
            {
                if(word[charIndex] != word[word.size() - charIndex - 1])
                {
                    palindromeFlag = false;
                    break;
                }
            }
            if(palindromeFlag == true)
            {
                retPalindrome = word;
                break;
            }
        }
        return retPalindrome;
    }
};