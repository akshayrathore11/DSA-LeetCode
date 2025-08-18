#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // agar array empty ho â return ""

        string prefix = strs[0]; // pehli string ko base bana liya

        // baaki strings ke saath compare karo
        for (int i = 1; i < strs.size(); i++) {
            // prefix ko chhota karte jao jab tak match na ho
            while (strs[i].find(prefix) != 0) {
                // agar prefix match nahi karta â last character hata do
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return ""; // agar kuch nahi bacha â return ""
            }
        }

        return prefix; // final common prefix return karo
    }
};