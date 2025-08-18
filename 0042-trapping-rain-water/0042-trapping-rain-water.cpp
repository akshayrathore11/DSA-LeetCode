class Solution {
public:
    int trap(vector<int>& height) {
      
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        while (left < right) {

            // Agar left wali height chhoti hai right se
            if (height[left] < height[right]) {

                // Check karo ki ab tak ka leftMax chhota ya bada hai
                if (height[left] >= leftMax) {
                    // Agar current height badi hai, to yeh new leftMax ban jayegi
                    leftMax = height[left];
                } else {
                    // Agar chhoti hai, iska matlab is position pe pani ruk sakta hai
                    // Pani = leftMax - currentHeight
                    water += leftMax - height[left];
                }

                // Ab left ko aage badhao
                left++;
            } 
            // Agar right side height chhoti ya barabar hai
            else {

                // Check karo ki ab tak ka rightMax chhota ya bada hai
                if (height[right] >= rightMax) {
                    // Agar current height badi hai, to yeh new rightMax ban jayegi
                    rightMax = height[right];
                } else {
                    // Agar chhoti hai, iska matlab is position pe pani ruk sakta hai
                    // Pani = rightMax - currentHeight
                    water += rightMax - height[right];
                }

             
                right--;
            }
        }
        return water;
    }
};
