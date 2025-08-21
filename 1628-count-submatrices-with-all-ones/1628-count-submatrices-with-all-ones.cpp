#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();      
        int n = mat[0].size();  
        int ans = 0;
   
        vector<int> heights(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    heights[j] += 1; 
                } else {
                    heights[j] = 0;  
                }
            }
            for (int j = 0; j < n; j++) {
                int minHeight = heights[j];  
                for (int k = j; k >= 0 && minHeight > 0; k--) {     
                    minHeight = min(minHeight, heights[k]);
                    ans += minHeight;  
                  
                }
            }
        }

        return ans;
    }
};
