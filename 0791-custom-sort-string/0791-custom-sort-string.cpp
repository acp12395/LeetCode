class Solution {
public:
    string customSortString(string order, string s) {
        string customSortedString;
        vector<pair<int,int>> orderCountVector(27,{-1,-1});
        vector<pair<int,int>> charCountVector(27,{-1,-1});
        for(int index = 0; index < order.size(); index++)
        {
            charCountVector[order[index] - 96] = {0,index};
            orderCountVector[index] = {0,order[index] - 96};
        }
        for(auto& character : s)
        {
            if(charCountVector[character - 96].first == -1)
            {
                customSortedString.push_back(character);
            }
            else
            {
                charCountVector[character - 96].first++;
                orderCountVector[charCountVector[character - 96].second].first++;
            }
        }
        for(int charOrder = 0; charOrder < order.size(); charOrder++)
        {
            customSortedString.insert(customSortedString.size(), orderCountVector[charOrder].first, orderCountVector[charOrder].second + 96);
        }
        return customSortedString;
    }
};