class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        # Precompute palindromes
        isPal = [[False] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and (j - i < 2 or isPal[i + 1][j - 1]):
                    isPal[i][j] = True

        # DP for min cuts
        dp = [0] * n
        for i in range(n):
            if isPal[0][i]:
                dp[i] = 0
            else:
                dp[i] = min(dp[j - 1] + 1 for j in range(1, i + 1) if isPal[j][i])
        return dp[-1]
