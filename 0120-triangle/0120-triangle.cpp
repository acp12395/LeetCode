class Solution {
private:
    int minimumTotalHelper(vector<vector<int>>& triangle, vector<vector<int>>& minimumSumTriangle, int level)
    {
        int minVal = INT_MAX;
        minimumSumTriangle.push_back(vector<int>());
        if(level == 0)
        {
            minimumSumTriangle[level].push_back(triangle[level][0]);
            minVal = triangle[level][0];
        }
        else
        {
            minimumTotalHelper(triangle, minimumSumTriangle, level - 1);
            for(int i = 0; i < triangle[level].size(); i++)
            {
                int previousLeft = INT_MAX;
                int previousRight = INT_MAX;
                if(i > 0)
                {
                    previousLeft = minimumSumTriangle[level - 1][i - 1];
                }
                if(i < triangle[level].size() - 1)
                {
                    previousRight = minimumSumTriangle[level - 1][i];
                }
                int newElement = triangle[level][i] + min(previousLeft, previousRight);
                minimumSumTriangle[level].push_back(newElement);
                minVal = min(newElement, minVal);
            }
        }
        return minVal;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> minimumSumTriangle;
        return minimumTotalHelper(triangle, minimumSumTriangle, triangle.size() - 1);
    }
};