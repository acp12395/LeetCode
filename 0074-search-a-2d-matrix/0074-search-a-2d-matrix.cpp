class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;
        int mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(matrix[mid][0] < target && matrix[mid][matrix[0].size() - 1] < target)
            {
                low = mid + 1;
            }
            else if(matrix[mid][0] <= target && matrix[mid][matrix[0].size() - 1] >= target)
            {
                break;
            }
            else if(matrix[mid][0] > target && matrix[mid][matrix[0].size() - 1] > target)
            {
                high = mid - 1;
            }
        }
        low = 0;
        high = matrix[0].size() - 1;
        int rowIndex = mid;
        bool retVal = false;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(matrix[rowIndex][mid] < target)
            {
                low = mid + 1;
            }
            else if(matrix[rowIndex][mid] == target)
            {
                retVal = true;
                break;
            }
            else if(matrix[rowIndex][mid] > target)
            {
                high = mid - 1;
            }
        }
        return retVal;
    }
};