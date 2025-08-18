#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // ye deque me hum sirf indexes rakhenge
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Step 1: Window ke bahar ke indexes ko hatao (front se)
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Step 2: Peeche se chhote elements hatao
            // kyunki agar koi bada element aa gaya to chhote wala kabhi max nahi banega
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Step 3: Current index ko daalo deque me
            dq.push_back(i);

            // Step 4: Jab ek valid window ban jaaye (i >= k-1)
            // tab answer me front element ka value daal do
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
