class Solution {
private:
    void getMaximumGoldHelper(vector<vector<int>>& grid, int rowIndex, int colIndex, stack<int>& collectedGoldStack, int& goldSum, int&maxGold)
    {
        collectedGoldStack.push(grid[rowIndex][colIndex]);
        goldSum += grid[rowIndex][colIndex];
        grid[rowIndex][colIndex] = 0;
        maxGold = goldSum > maxGold ? goldSum : maxGold;
        if(rowIndex > 0 && grid[rowIndex - 1][colIndex] > 0)
        {
            getMaximumGoldHelper(grid, rowIndex - 1, colIndex, collectedGoldStack, goldSum, maxGold);
        }
        if(rowIndex < grid.size() - 1 && grid[rowIndex + 1][colIndex] > 0)
        {
            getMaximumGoldHelper(grid, rowIndex + 1, colIndex, collectedGoldStack, goldSum, maxGold);
        }
        if(colIndex > 0 && grid[rowIndex][colIndex - 1] > 0)
        {
            getMaximumGoldHelper(grid, rowIndex, colIndex - 1, collectedGoldStack, goldSum, maxGold);
        }
        if(colIndex < grid[0].size() - 1 && grid[rowIndex][colIndex + 1] > 0)
        {
            getMaximumGoldHelper(grid, rowIndex, colIndex + 1, collectedGoldStack, goldSum, maxGold);
        }
        grid[rowIndex][colIndex] = collectedGoldStack.top();
        goldSum -= grid[rowIndex][colIndex];
        collectedGoldStack.pop();
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        stack<int> goldCollector;
        for(int rowIndex = 0; rowIndex < grid.size(); rowIndex++)
        {
            for(int colIndex = 0; colIndex < grid[0].size(); colIndex++)
            {
                if(grid[rowIndex][colIndex] > 0)
                {
                    int goldSum = 0;
                    getMaximumGoldHelper(grid, rowIndex, colIndex, goldCollector, goldSum, res);
                }
            }
        }
        return res;
    }
};