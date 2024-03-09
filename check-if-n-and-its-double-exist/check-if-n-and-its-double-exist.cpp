class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> l_arr = arr;
        bool exist = false;
        sort(l_arr.begin(), l_arr.end());
        int index = 0, doubleIndex = 0;
        while(doubleIndex < l_arr.size() && index < l_arr.size())
        {
            if(l_arr[doubleIndex] < l_arr[index]*2)
            {
                doubleIndex++;
            }
            else if(l_arr[doubleIndex] > l_arr[index]*2)
            {
                index++;
            }
            else if(!(l_arr[index] == 0 && index == doubleIndex))
            {
                exist = true;
                break;
            }
            else
            {
                doubleIndex++;
            }
        }
        return exist;
    }
};