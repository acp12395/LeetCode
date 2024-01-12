class Solution {
public:
    bool halvesAreAlike(string s) {
        int counter1 = 0, counter2 = 0;
        for(int i = 0; i < s.size()/2; i++)
        {
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U' || s[i] == 'a' ||
                s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u')
            {
                counter1++;
            }
        }
        for(int i = s.size()/2; i < s.size(); i++)
        {
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U' || s[i] == 'a' ||
                s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u')
            {
                counter2++;
            }
        }
        return (counter1 == counter2);
    }
};