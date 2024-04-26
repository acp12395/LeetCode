class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int minSum = grid[0][0];
        if(grid.size() != 1)
        {
            vector<vector<vector<int>>> mins;
            {
                vector<int> minsAndCells(2, INT_MAX);
                vector<vector<int>> prevAndCurrent;
                prevAndCurrent.push_back(minsAndCells);
                prevAndCurrent.push_back(minsAndCells);
                mins.push_back(prevAndCurrent);
                mins.push_back(prevAndCurrent);
            }
            const int prevIndex = 0, currIndex = 1;
            const int minIndex = 0, cellIndex = 1;
            const int first = 0, second = 1;
            mins[currIndex][minIndex][first] = 0;
            mins[currIndex][cellIndex][first] = 0;
            mins[currIndex][minIndex][second] = 0;
            mins[currIndex][cellIndex][second] = 1;
            for(int row = 0; row < grid.size(); row++)
            {
                swap(mins[prevIndex], mins[currIndex]);
                mins[currIndex][minIndex][first] = INT_MAX;
                mins[currIndex][minIndex][second] = INT_MAX;
                int minPrevIndex = mins[prevIndex][minIndex][first] > mins[prevIndex][minIndex][second] ? second : first;
                int maxPrevIndex = minPrevIndex == first ? second : first;
                for(int cell = 0; cell < grid[0].size(); cell++)
                {
                    int prevToSum = cell == mins[prevIndex][cellIndex][minPrevIndex] ? mins[prevIndex][minIndex][maxPrevIndex] : mins[prevIndex][minIndex][minPrevIndex];
                    int sum = prevToSum + grid[row][cell];
                    int indexMax = mins[currIndex][minIndex][first] > mins[currIndex][minIndex][second] ? first : second;
                    mins[currIndex][cellIndex][indexMax] = mins[currIndex][minIndex][indexMax] > sum ? cell : mins[currIndex][cellIndex][indexMax];
                    mins[currIndex][minIndex][indexMax] = mins[currIndex][minIndex][indexMax] > sum ? sum : mins[currIndex][minIndex][indexMax];
                }
            }
            minSum = mins[currIndex][minIndex][first] < mins[currIndex][minIndex][second] ? mins[currIndex][minIndex][first] : mins[currIndex][minIndex][second];
        }
        return minSum;
    }
};