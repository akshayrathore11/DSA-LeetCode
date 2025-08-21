#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false; // agar s1 bada hai s2 se, to impossible

        // Step 1: freq count of s1
        vector<int> freq1(26, 0), freq2(26, 0);
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        // Step 2: first window of size m in s2
        for (int i = 0; i < m; i++) {
            freq2[s2[i] - 'a']++;
        }

        // Step 3: check first window
        if (freq1 == freq2) return true;

        // Step 4: slide the window
        for (int i = m; i < n; i++) {
            // add new char in window
            freq2[s2[i] - 'a']++;
            // remove old char from window
            freq2[s2[i - m] - 'a']--;

            // check again
            if (freq1 == freq2) return true;
        }

        return false; // koi bhi window match nahi hua
    }
};
