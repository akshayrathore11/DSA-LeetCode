#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = sortedDigits(n);

        for (int i = 0; i < 31; i++) { 
            if (s == sortedDigits(1 << i)) {
                return true;
            }
        }
        return false;
    }

private:
    string sortedDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
};
