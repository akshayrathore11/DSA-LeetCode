class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, maxLen = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;

            // shrink if more than 1 zero
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            // length of window - 1 (delete one element)
            maxLen = max(maxLen, right - left);
        }
        
        return maxLen;
    }
};
