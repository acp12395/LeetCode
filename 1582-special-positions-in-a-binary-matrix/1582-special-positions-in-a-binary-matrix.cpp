class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int retVal = 0;
        int oneInNIndex;
        for(int m = 0; m < mat.size(); m++)
        {
            int onesCounter = 0;
            for(int n = 0; n < mat[m].size(); n++)
            {
                if(mat[m][n] == 1)
                {
                    onesCounter++;
                    oneInNIndex = n;
                    if(onesCounter > 1)
                    {
                        break;
                    }
                }
            }
            if(onesCounter == 1)
            {
                onesCounter = 0;
                for(int m2 = 0; m2 < mat.size(); m2++)
                {
                    if(mat[m2][oneInNIndex] == 1)
                    {
                        onesCounter++;
                        if(onesCounter > 1)
                        {
                            break;
                        }
                    }
                }
                if(onesCounter == 1)
                {
                    retVal++;
                }
            }
        }
        return retVal;
    }
};