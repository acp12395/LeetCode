class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxPow2Diag = 0;
        int maxArea = 0;
        for(auto& dimension : dimensions) 
        {
            int pow2Diag = pow(dimension[0],2) + pow(dimension[1],2);
            if(pow2Diag > maxPow2Diag)
            {
                maxPow2Diag = pow2Diag;
                maxArea = dimension[0] * dimension[1];
            }
            else if(pow2Diag == maxPow2Diag)
            {
                int area = dimension[0] * dimension[1];
                if(area > maxArea)
                {
                    maxArea = area;
                }
            }
        }
        return maxArea;
    }
};