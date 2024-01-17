class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> occurrencesMap;
        for(auto& number : arr)
        {
            occurrencesMap[number]++;
        }
        unordered_set<int> occurrencesSet;
        for(auto& [_,occurrence] : occurrencesMap)
        {
            if(!occurrencesSet.insert(occurrence).second)
            {
                return false;
            }
        }
        return true;
    }
};