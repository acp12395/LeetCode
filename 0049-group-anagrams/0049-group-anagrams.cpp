class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagramGroups;
        vector<string> strings = strs;
        unordered_map<string, int> stringsVectorIndexMap;
        vector<string> addVector;
        int vectorSize;
        for(int strIndex = 0; strIndex < strings.size(); strIndex++)
        {
            vectorSize = anagramGroups.size();
            sort(strings[strIndex].begin(), strings[strIndex].end());
            if(stringsVectorIndexMap.count(strings[strIndex]) == 0)
            {
                stringsVectorIndexMap[strings[strIndex]] = vectorSize;
                anagramGroups.push_back(addVector);
                anagramGroups[vectorSize].push_back(strs[strIndex]);
            }
            else
            {
                anagramGroups[stringsVectorIndexMap[strings[strIndex]]].push_back(strs[strIndex]);
            }
        }
        return anagramGroups;
    }
};