from math import gcd
from typing import List

class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        MOD = 10 ** 9 + 7
        M = 200

        dp = [[0] * (M + 1) for _ in range(M + 1)]
        dp[0][0] = 1

        for x in nums:
            ndp = [row[:] for row in dp]  # option: ignore x

            for g1 in range(M + 1):
                row = dp[g1]
                for g2 in range(M + 1):
                    cur = row[g2]
                    if cur == 0:
                        continue

                    ng1 = x if g1 == 0 else gcd(g1, x)
                    ndp[ng1][g2] = (ndp[ng1][g2] + cur) % MOD

                    ng2 = x if g2 == 0 else gcd(g2, x)
                    ndp[g1][ng2] = (ndp[g1][ng2] + cur) % MOD

            dp = ndp

        ans = 0
        for g in range(1, M + 1):
            ans = (ans + dp[g][g]) % MOD

        return ans
