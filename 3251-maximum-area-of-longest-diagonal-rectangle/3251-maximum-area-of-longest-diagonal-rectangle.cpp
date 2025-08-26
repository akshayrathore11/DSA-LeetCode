class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal = 0; 
        int maxArea = 0;
        
        for (auto& rect : dimensions) {
            int l = rect[0], w = rect[1];
            int diag = l*l + w*w;  
            int area = l * w;
            
            if (diag > maxDiagonal) {
                maxDiagonal = diag;
                maxArea = area;
            } else if (diag == maxDiagonal) {
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};
