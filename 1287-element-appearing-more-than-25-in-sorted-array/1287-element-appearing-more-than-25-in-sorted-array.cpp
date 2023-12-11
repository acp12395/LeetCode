class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int retVal;
        const int sizeQuarter = arr.size()/4;
        const int size3Quarters = arr.size()*3/4;
        int lastSavedInt = -1;
        int sameNumberCounter = 0;
        for(auto& i : arr)
        {
            if(i != lastSavedInt)
            {
                sameNumberCounter = 1;
                lastSavedInt = i;
            }
            else
            {
                sameNumberCounter++;
                if(sameNumberCounter > sizeQuarter)
                {
                    retVal = lastSavedInt;
                    break;
                }
            }
        }
        return retVal;
    }
};