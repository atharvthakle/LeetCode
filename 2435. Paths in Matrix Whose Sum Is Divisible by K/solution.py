class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        MOD = 10**9 + 7
        m, n = len(grid), len(grid[0])

        # dp[j][r] = ways to reach (cur_row, j) with sum % k == r
        dp = [[0] * k for _ in range(n)]

        # Initialize first cell
        dp[0][grid[0][0] % k] = 1

        for i in range(m):
            new_dp = [[0] * k for _ in range(n)]
            for j in range(n):
                val = grid[i][j] % k
                if i == 0 and j == 0:
                    new_dp[0][val] = 1
                    continue

                # From top (i-1, j)
                if i > 0:
                    for r in range(k):
                        nr = (r + val) % k
                        new_dp[j][nr] = (new_dp[j][nr] + dp[j][r]) % MOD

                # From left (i, j-1)
                if j > 0:
                    for r in range(k):
                        nr = (r + val) % k
                        new_dp[j][nr] = (new_dp[j][nr] + new_dp[j-1][r]) % MOD

            dp = new_dp  # shift to next row

        # Ways to end at bottom-right with remainder 0
        return dp[n-1][0] % MOD
