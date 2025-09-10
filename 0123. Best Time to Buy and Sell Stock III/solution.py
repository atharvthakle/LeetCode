class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        # First buy and sell
        first_buy = float('-inf')
        first_sell = 0
        # Second buy and sell
        second_buy = float('-inf')
        second_sell = 0
        
        for price in prices:
            # Max profit after first buy (we spend money)
            first_buy = max(first_buy, -price)
            # Max profit after first sell
            first_sell = max(first_sell, first_buy + price)
            # Max profit after second buy (subtract price from first_sell)
            second_buy = max(second_buy, first_sell - price)
            # Max profit after second sell
            second_sell = max(second_sell, second_buy + price)
        
        return second_sell
