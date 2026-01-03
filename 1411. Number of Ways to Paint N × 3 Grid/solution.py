class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 10**9 + 7
        
        # dpA: ABC patterns, dpB: ABA patterns
        dpA, dpB = 6, 6
        
        for _ in range(2, n + 1):
            newA = (2 * dpA + 2 * dpB) % MOD
            newB = (2 * dpA + 3 * dpB) % MOD
            dpA, dpB = newA, newB
        
        return (dpA + dpB) % MOD
