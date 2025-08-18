#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // \U0001f539 Map rakhega ki ek particular prefix sum kitni baar aaya hai
        unordered_map<int, int> prefixCount;  
        
        // \U0001f539 Initially prefix sum = 0 ek baar hua hai (empty subarray ke liye)
        prefixCount[0] = 1;  

        int currSum = 0; // ab tak ka running sum
        int count = 0;   // answer (kitne subarrays mile jinka sum = k)

        // \U0001f539 Har element traverse karo
        for (int num : nums) {
            currSum += num;  // running sum update kar diya

            // \U0001f539 Check karo kya koi aisa prefix sum exist karta hai
            // jisse current sum - k ban raha ho
            // iska matlab us prefix ke baad ka subarray sum = k hai
            if (prefixCount.find(currSum - k) != prefixCount.end()) {
                count += prefixCount[currSum - k]; 
                // utni baar subarray mila jitni baar (currSum-k) aaya hai
            }

            // \U0001f539 Ab current sum ko bhi map me daal do
            prefixCount[currSum]++;
        }

        return count; // final answer
    }
};
