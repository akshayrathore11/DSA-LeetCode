class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n * n;
        
        long long actualSum = 0;
        long long actualSumSq = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long long val = grid[i][j];
                actualSum += val;
                actualSumSq += val * val;
            }
        }

        long long expectedSum = N * (N + 1) / 2;
        long long expectedSumSq = N * (N + 1) * (2 * N + 1) / 6;

        long long sumDiff = actualSum - expectedSum;       // a - b
        long long sumSqDiff = actualSumSq - expectedSumSq; // a^2 - b^2

        // a^2 - b^2 = (a - b)(a + b)
        // (a + b) = (a^2 - b^2) / (a - b)
        long long sum_a_b = sumSqDiff / sumDiff;

        // We have two equations:
        // 1. a - b = sumDiff
        // 2. a + b = sum_a_b
        
        // Adding the two equations: 2a = sumDiff + sum_a_b
        long long repeatedNum = (sumDiff + sum_a_b) / 2;
        
        // Subtracting the first from the second: 2b = sum_a_b - sumDiff
        long long missingNum = (sum_a_b - sumDiff) / 2;
        
        return {(int)repeatedNum, (int)missingNum};
    }
};