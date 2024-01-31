class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        map<int,int> tempIndexMap;
        for(int index = temperatures.size() - 1; index >= 0; index--)
        {
            auto warmerTempIndex = tempIndexMap.upper_bound(temperatures[index]);
            if(warmerTempIndex == tempIndexMap.end())
            {
                answer[index] = 0;
            }
            else
            {
                int minIndex = INT_MAX;
                while (warmerTempIndex != tempIndexMap.end())
                {
                    if((*warmerTempIndex).second < minIndex)
                    {
                        minIndex = (*warmerTempIndex).second;
                    }
                    warmerTempIndex++;
                }
                answer[index] = minIndex - index;
            }
            tempIndexMap[temperatures[index]] = index;
        }
        return answer;
    }
};