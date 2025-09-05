from collections import defaultdict
from typing import List

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        # dp[val][c] = max subsequence length ending with 'val' using c changes
        dp = defaultdict(lambda: [0] * (k + 1))
        best = [0] * (k + 1)   # best[c] = best length using exactly c changes
        ans = 0

        for x in nums:
            new_dp = dp[x][:]  # copy only dp[x] row (cheap, O(k))

            for c in range(k + 1):
                # Case 1: continue subsequence ending with x (no new change)
                if dp[x][c] > 0:
                    new_dp[c] = max(new_dp[c], dp[x][c] + 1)

                # Case 2: extend from a different ending value (add +1 change)
                if c > 0 and best[c - 1] > 0:
                    new_dp[c] = max(new_dp[c], best[c - 1] + 1)

            # Case 3: start a new subsequence with x
            new_dp[0] = max(new_dp[0], 1)

            dp[x] = new_dp
            for c in range(k + 1):
                best[c] = max(best[c], new_dp[c])

            ans = max(ans, max(new_dp))

        return ans
