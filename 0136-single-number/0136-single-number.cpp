class Solution {
public:
    int singleNumber(vector<int>& numbers) {
        int xorResult = 0;
        for (int number : numbers) {
            xorResult ^= number;
        }
        return xorResult;
    }
};