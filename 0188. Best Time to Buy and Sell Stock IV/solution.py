class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if n == 0:
            return 0
        
        # If k >= n//2, we can make as many transactions as we want
        if k >= n // 2:
            profit = 0
            for i in range(1, n):
                if prices[i] > prices[i-1]:
                    profit += prices[i] - prices[i-1]
            return profit
        
        # DP arrays: hold max profit for up to k transactions
        buy = [float('-inf')] * (k + 1)
        sell = [0] * (k + 1)
        
        for price in prices:
            for j in range(1, k + 1):
                buy[j] = max(buy[j], sell[j-1] - price)  # Max profit after j-th buy
                sell[j] = max(sell[j], buy[j] + price)   # Max profit after j-th sell
        
        return sell[k]
