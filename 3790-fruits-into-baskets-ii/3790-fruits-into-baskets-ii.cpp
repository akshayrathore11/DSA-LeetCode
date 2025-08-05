class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);
        int unplaced = 0;

        for (int i = 0; i < n; ++i) {
            int fruitQty = fruits[i];
            int j = 0;

            while (j < n && (used[j] || baskets[j] < fruitQty)) {
                ++j;
            }

            if (j < n) {
                used[j] = true;
            } else {
                ++unplaced;
            }
        }

        return unplaced;
    }
};
