class Solution {
private:
    int insertBinarySearch(vector<vector<int>>& intervals, int num)
    {
        int low = 0;
        int high = intervals.size() - 1;
        int mid = 0;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(intervals[mid][1] < num)
            {
                low = mid + 1;
            }
            else if(intervals[mid][1] <= num)
            {
                break;
            }
            else
            {
                high = mid - 1;
            }
        }
        if(intervals[mid][1] < num)
        {
            mid++;
        }
        return mid;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> retVal;
        if(intervals.size() > 0)
        {
            int newIntervalStartIndex = insertBinarySearch(intervals, newInterval[0]);
            int newIntervalEndIndex = insertBinarySearch(intervals, newInterval[1]);
            retVal.insert(retVal.end(), intervals.begin(), intervals.begin() + newIntervalStartIndex);
            if(newIntervalStartIndex < intervals.size())
            {
                retVal.push_back({min(newInterval[0], intervals[newIntervalStartIndex][0]), newInterval[1]});
            }
            else
            {
                retVal.push_back({newInterval[0], newInterval[1]});
            }
            if(newIntervalEndIndex < intervals.size())
            {
                retVal.back()[1] = retVal.back()[1] < intervals[newIntervalEndIndex][0] ? retVal.back()[1] : intervals[newIntervalEndIndex][1];
                retVal.insert(retVal.end(), newInterval[1] < intervals[newIntervalEndIndex][0] ? intervals.begin() + newIntervalEndIndex : intervals.begin() + (newIntervalEndIndex + 1), intervals.end());
            }
            else
            {
                retVal.back()[1] = retVal.back()[1];
            }
        }
        else
        {
            retVal.push_back(newInterval);
        }
        return retVal;
    }
};