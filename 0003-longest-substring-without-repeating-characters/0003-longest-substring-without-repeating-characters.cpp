class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_set<char> seen;  // to store characters in the current window
        int left = 0;              // left pointer of the window
        int maxLen = 0;            // answer: longest substring length

        // Expand the window with 'right' pointer
        for (int right = 0; right < s.size(); right++) {
            // If we see a duplicate, shrink window from the left
            while (seen.count(s[right])) {
                seen.erase(s[left]);  // remove left character
                left++;               // move left pointer ahead
            }

            // Add current character to set
            seen.insert(s[right]);

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};