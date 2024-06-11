class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> arr1CountMap;
        for(auto& num : arr1)
        {
            arr1CountMap[num]++;
        }
        vector<int> res;
        for(auto& num : arr2)
        {
            int count = arr1CountMap[num];
            for(int i = 0; i < count; i++)
            {
                res.push_back(num);
            }
            arr1CountMap.erase(num);
        }
        vector<int> remainingNums;
        for(auto& [num,count] : arr1CountMap)
        {
            for(int i = 0; i < count; i++)
            {
                remainingNums.push_back(num);
            }
        }
        sort(remainingNums.begin(), remainingNums.end());
        res.insert(res.end(),remainingNums.begin(),remainingNums.end());
        return res;
    }
};