class Solution {
public:
    int search(vector<int>& nums, int target) {
         int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // beech ka index nikal lo

            // agar mid hi target hai to direct return kardo
            if (nums[mid] == target) {
                return mid;
            }

            // check karo left half sorted hai kya
            if (nums[low] <= nums[mid]) {
                // agar target iske beech me aata hai
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;  // left half me search karo
                } else {
                    low = mid + 1;   // warna right half me jao
                }
            }
            // warna right half sorted hoga
            else {
                // agar target right half me hai
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;   // right half me search karo
                } else {
                    high = mid - 1;  // left half me jao
                }
            }
        }

        // agar kahin bhi na mila to return -1
        return -1;
    }
};