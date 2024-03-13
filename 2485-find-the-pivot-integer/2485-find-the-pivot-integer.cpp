class Solution {
public:
    int pivotInteger(int n) {
        int pivot = -1;
        vector<float> indexSumVector(n + 1, 0);
        for(int index = 1; index <= n; index++)
        {
            indexSumVector[index] = (indexSumVector[index - 1] + index);
        }
        for(int sumIndex = 1; sumIndex <= n; sumIndex++)
        {
            if(indexSumVector[sumIndex]*2 - sumIndex == indexSumVector.back())
            {
                pivot = sumIndex;
                break;
            }
        }
        return pivot;
    }
};