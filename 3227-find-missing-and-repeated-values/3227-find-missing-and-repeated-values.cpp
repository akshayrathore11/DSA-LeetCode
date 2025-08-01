class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
         int n = grid.size();
    long long actualSum = 0, actualSquareSum = 0;
    long long totalElements = n * n;

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            long long value = grid[row][col];
            actualSum += value;
            actualSquareSum += value * value;
        }
    }

    long long expectedSum = totalElements * (totalElements + 1) / 2;
    long long expectedSquareSum = totalElements * (totalElements + 1) * (2 * totalElements + 1) / 6;

    long long sumDifference = actualSum - expectedSum;
    long long squareSumDifference = actualSquareSum - expectedSquareSum; 

    long long sumOfBoth = squareSumDifference / sumDifference;

    long long duplicate = (sumDifference + sumOfBoth) / 2;
    long long missing = duplicate - sumDifference;

    return {static_cast<int>(duplicate), static_cast<int>(missing)};
    }
};