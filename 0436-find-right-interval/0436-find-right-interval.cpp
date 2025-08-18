class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> startsVec;
        map<int,int> startsIndexMap;
        for(int index = 0; index <= intervals.size() - 1; index++)
        {
            int start = intervals[index][0];
            startsVec.push_back(start);
            startsIndexMap[start] = index;
        }
        sort(startsVec.begin(),startsVec.end());
        vector<int> retVec;
        for(int index = 0; index <= intervals.size() - 1; index++)
        {
            int low = 0;
            int high = startsVec.size() - 1;
            int mid;
            while(low <= high)
            {
                mid = (low + high) / 2;
                if(startsVec[mid] == intervals[index][1])
                {
                    retVec.push_back(startsIndexMap[startsVec[mid]]);
                    break;
                }
                else if(startsVec[mid] > intervals[index][1])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            if(startsVec[mid] > intervals[index][1])
            {
                retVec.push_back(startsIndexMap[startsVec[mid]]);
            }
            else if(startsVec[mid] < intervals[index][1])
            {
                if(mid < startsVec.size() - 1)
                {
                    retVec.push_back(startsIndexMap[startsVec[mid + 1]]);
                }
                else
                {
                    retVec.push_back(-1);
                }
            }
        }
        return retVec;
    }
};