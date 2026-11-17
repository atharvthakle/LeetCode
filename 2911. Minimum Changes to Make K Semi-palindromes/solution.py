class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        INF = float('inf')

        cost = [[INF] * (n + 1) for _ in range(n)]

        for i in range(n):
            for length in range(2, n - i + 1):
                for d in range(1, length):
                    if length % d != 0:
                        continue

                    changes = 0
                    group_len = length // d

                    for r in range(d):
                        left = i + r
                        right = i + r + (group_len - 1) * d

                        while left < right:
                            if s[left] != s[right]:
                                changes += 1
                            left += d
                            right -= d

                    cost[i][i + length] = min(
                        cost[i][i + length], changes
                    )

        dp = [[INF] * (n + 1) for _ in range(k + 1)]
        dp[0][0] = 0

        for parts in range(1, k + 1):
            for end in range(parts * 2, n + 1):
                for start in range((parts - 1) * 2, end - 1):
                    dp[parts][end] = min(
                        dp[parts][end],
                        dp[parts - 1][start] + cost[start][end]
                    )

        return dp[k][n]
