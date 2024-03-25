class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> numCountMap;
        vector<int> duplicatesVector;
        for(int i = 1; i <= 100000; i++)
        {
            numCountMap[i] = 0;
            duplicatesVector.push_back(i);
        }
        for(auto& num : nums)
        {
            numCountMap[num]++;
        }
        vector<int>::iterator it = duplicatesVector.begin();
        while(it < duplicatesVector.end())
        {
            while(numCountMap[*it] != 2 && it < duplicatesVector.end())
            {
                swap(*it, *(duplicatesVector.end()-1));
                duplicatesVector.pop_back();
            }
            it++;
        }
        return duplicatesVector;
    }
};