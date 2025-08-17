class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1, n = nums.size();

        // Find the pivot point (rightmost element that is smaller than its next element)
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot found, array is in descending order, so reverse it
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the smallest element greater than pivot from the right
        for(int i = n-1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Reverse the elements after pivot
        int i = pivot + 1, j = n - 1;
        while(i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
};
