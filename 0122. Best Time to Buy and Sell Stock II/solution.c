int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    for (int i = 1; i < pricesSize; i++) {
        // If price increased from previous day, we "sell" to capture profit
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}
