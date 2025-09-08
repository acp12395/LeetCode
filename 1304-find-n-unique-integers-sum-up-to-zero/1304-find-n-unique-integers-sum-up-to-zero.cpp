class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> retVec;
        for(int i = 1; i <= n/2; i++)
        {
            retVec.push_back(i);
            retVec.push_back(-i);
        }
        if(n%2 == 1)
        {
            retVec.push_back(0);
        }
        return retVec;
    }
};