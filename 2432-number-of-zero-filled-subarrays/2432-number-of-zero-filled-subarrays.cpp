#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;    // total zero-filled subarrays
        long long streak = 0;   // current consecutive zeros streak

        for (int num : nums) {
            if (num == 0) {
                streak++;          // zero mila â streak badhao
                count += streak;   // streak ke hisaab se subarrays add karo
            } else {
                streak = 0;        // non-zero mila â streak reset
            }
        }

        return count; // total zero-filled subarrays
    }
};
