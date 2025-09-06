from typing import List
import functools

class Solution:
    def mergeStones(self, stones: List[int], k: int) -> int:
        n = len(stones)
        if (n - 1) % (k - 1) != 0:
            return -1

        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stones[i]

        @functools.lru_cache(None)
        def dp(i, j, m):
            if (j - i + 1 - m) % (k - 1) != 0:
                return float("inf")
            if i == j:
                return 0 if m == 1 else float("inf")
            if m == 1:
                return dp(i, j, k) + prefix[j + 1] - prefix[i]
            res = float("inf")
            for mid in range(i, j, k - 1):
                res = min(res, dp(i, mid, 1) + dp(mid + 1, j, m - 1))
            return res

        return dp(0, n - 1, 1)
