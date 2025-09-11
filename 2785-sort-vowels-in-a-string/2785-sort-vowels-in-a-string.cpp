class Solution {
public:
    string sortVowels(string s) {
        string t;
        vector<char> vowels;
        for(auto& character : s)
        {
            if(character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U' || character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u')
            {
                vowels.push_back(character);
            }
        }
        sort(vowels.rbegin(), vowels.rend());
        for(auto& character : s)
        {
            if(character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U' || character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u')
            {
                t.push_back(vowels.back());
                vowels.pop_back();
            }
            else
            {
                t.push_back(character);
            }
        }
        return t;
    }
};