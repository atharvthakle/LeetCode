class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)

        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stoneValue[i]

        dp = [[0] * n for _ in range(n)]

        # left[i][j] = max(dp[i][k] + sum(i..k)) for i <= k <= j
        # right[i][j] = max(dp[k][j] + sum(k..j)) for i <= k <= j
        left = [[0] * n for _ in range(n)]
        right = [[0] * n for _ in range(n)]

        for i in range(n):
            left[i][i] = stoneValue[i]
            right[i][i] = stoneValue[i]

        for length in range(2, n + 1):
            for l in range(n - length + 1):
                r = l + length - 1

                total = prefix[r + 1] - prefix[l]

                # Find first split where left sum >= right sum
                lo, hi = l, r - 1
                split = r

                while lo <= hi:
                    mid = (lo + hi) // 2
                    leftSum = prefix[mid + 1] - prefix[l]
                    rightSum = total - leftSum

                    if leftSum >= rightSum:
                        split = mid
                        hi = mid - 1
                    else:
                        lo = mid + 1

                # All splits before 'split' have leftSum < rightSum
                if split > l:
                    dp[l][r] = max(dp[l][r], left[l][split - 1])

                if split < r:
                    leftSum = prefix[split + 1] - prefix[l]
                    rightSum = total - leftSum

                    if leftSum == rightSum:
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][split],
                            rightSum + dp[split + 1][r]
                        )
                    else:
                        # leftSum > rightSum, keep right side
                        dp[l][r] = max(dp[l][r], right[split + 1][r])

                # Update helper maximum arrays
                value = total + dp[l][r]

                left[l][r] = max(left[l][r - 1], value)
                right[l][r] = max(right[l + 1][r], value)

        return dp[0][n - 1]
