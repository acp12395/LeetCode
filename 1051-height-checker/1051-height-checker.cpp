class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        sort(sortedHeights.begin(), sortedHeights.end());
        int numberWrongIndices = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            if(heights[i] != sortedHeights[i])
            {
                numberWrongIndices++;
            }
        }
        return numberWrongIndices;
    }
};