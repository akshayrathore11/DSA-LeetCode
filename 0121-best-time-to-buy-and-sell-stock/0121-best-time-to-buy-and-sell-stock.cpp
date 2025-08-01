class Solution {
public:
    int maxProfit(vector<int>& stockPrices) {
         int minPriceSoFar = INT_MAX;
    int maxProfitSoFar = 0;

    for (int currentPrice : stockPrices) {
        if (currentPrice < minPriceSoFar) {
            minPriceSoFar = currentPrice;
        } else {
            int potentialProfit = currentPrice - minPriceSoFar;
            if (potentialProfit > maxProfitSoFar) {
                maxProfitSoFar = potentialProfit;
            }
        }
    }

    return maxProfitSoFar;
    }
};