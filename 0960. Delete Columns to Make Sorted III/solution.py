from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n, m = len(strs), len(strs[0])
        dp = [1] * m  # dp[j] = longest sequence ending at column j
        
        for j in range(m):
            for k in range(j):
                # Check if column k -> j is valid across all rows
                if all(strs[i][k] <= strs[i][j] for i in range(n)):
                    dp[j] = max(dp[j], dp[k] + 1)
        
        # Longest subsequence length we can keep
        keep = max(dp)
        return m - keep
