class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        from functools import lru_cache
        
        INF = float('inf')

        @lru_cache(None)
        def dp(i, prev_color, neighborhoods):
            # If neighborhoods exceed target → invalid
            if neighborhoods > target:
                return INF
            
            # If all houses processed
            if i == m:
                return 0 if neighborhoods == target else INF

            # If house is already painted
            if houses[i] != 0:
                new_neigh = neighborhoods + (1 if houses[i] != prev_color else 0)
                return dp(i + 1, houses[i], new_neigh)

            # Otherwise, try all possible colors
            ans = INF
            for color in range(1, n + 1):
                new_neigh = neighborhoods + (1 if color != prev_color else 0)
                ans = min(ans, cost[i][color - 1] + dp(i + 1, color, new_neigh))
            return ans

        res = dp(0, 0, 0)
        return res if res != INF else -1
