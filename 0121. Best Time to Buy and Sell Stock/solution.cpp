class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // Track the lowest price so far
        int maxProfit = 0;        // Track the max profit

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;  // Update minimum price
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;  // Update max profit
            }
        }
        return maxProfit;
    }
};
