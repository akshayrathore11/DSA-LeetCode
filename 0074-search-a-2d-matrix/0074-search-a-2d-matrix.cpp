class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int numRows = matrix.size();
        int numCols = matrix[0].size();
        
        int low = 0;
        int high = numRows * numCols - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int rowIndex = mid / numCols;
            int colIndex = mid % numCols;

            int currentValue = matrix[rowIndex][colIndex];

            if (currentValue == target) {
                return true;
            } else if (currentValue < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};