class Solution {
public:
    string longestPalindrome(string s) {
        string retStr;
        vector<pair<int,int>> oddLengthStrsIndexes;
        vector<pair<int,int>> pairLengthStrsIndexes;
        pair<int,int> longestOddStrIndexes({-1,-1});
        pair<int,int> longestPairStrIndexes({-1,-1});

        for(int i = 0; i < s.size(); i++)
        {
            oddLengthStrsIndexes.push_back({i,i});
            longestOddStrIndexes = {i,i};
            if(i < s.size() - 1)
            {
                if(s[i] == s[i+1])
                {
                    pairLengthStrsIndexes.push_back({i,i+1});
                    longestPairStrIndexes = {i,i+1};
                }
            }
        }

        for(int oddSize = 3; oddSize <= s.size(); oddSize = oddSize + 2)
        {
            for(int i = 0; i < oddLengthStrsIndexes.size(); i++)
            {
                if(oddLengthStrsIndexes[i].first - 1 >= 0 && oddLengthStrsIndexes[i].second + 1 < s.size() && s[oddLengthStrsIndexes[i].first - 1] == s[oddLengthStrsIndexes[i].second + 1])
                {
                    oddLengthStrsIndexes[i].first--;
                    oddLengthStrsIndexes[i].second++;
                    longestOddStrIndexes = {oddLengthStrsIndexes[i].first, oddLengthStrsIndexes[i].second};
                }
                else
                {
                    swap(oddLengthStrsIndexes[i], oddLengthStrsIndexes.back());
                    oddLengthStrsIndexes.pop_back();
                    i--;
                }
            }
            for(int i = 0; i < pairLengthStrsIndexes.size(); i++)
            {
                if(pairLengthStrsIndexes[i].first - 1 >= 0 && pairLengthStrsIndexes[i].second + 1 < s.size() && s[pairLengthStrsIndexes[i].first - 1] == s[pairLengthStrsIndexes[i].second + 1])
                {
                    pairLengthStrsIndexes[i].first--;
                    pairLengthStrsIndexes[i].second++;
                    longestPairStrIndexes = {pairLengthStrsIndexes[i].first, pairLengthStrsIndexes[i].second};
                }
                else
                {
                    swap(pairLengthStrsIndexes[i], pairLengthStrsIndexes.back());
                    pairLengthStrsIndexes.pop_back();
                    i--;
                }
            }
        }

        if((longestOddStrIndexes.second - longestOddStrIndexes.first + 1) < (longestPairStrIndexes.second - longestPairStrIndexes.first + 1))
        {
            retStr = s.substr(longestPairStrIndexes.first, longestPairStrIndexes.second - longestPairStrIndexes.first + 1);
        }
        else
        {
            retStr = s.substr(longestOddStrIndexes.first, longestOddStrIndexes.second - longestOddStrIndexes.first + 1);
        }
        return retStr;
    }
};