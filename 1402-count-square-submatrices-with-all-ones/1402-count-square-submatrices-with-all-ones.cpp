#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();       // rows
        int n = matrix[0].size();    // cols

        // dp[i][j] = size of largest square ending at (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int totalSquares = 0;

        // Traverse the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        // First row or first col â only 1x1 square possible
                        dp[i][j] = 1;
                    } else {
                        // Otherwise take min of top, left, diagonal
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                }
                
                totalSquares += dp[i][j]; // Add contribution of this cell
            }
        }

        return totalSquares;
    }
};
