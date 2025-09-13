class Solution:
    def numberOfUniqueGoodSubsequences(self, binary: str) -> int:
        MOD = 10**9 + 7
        dp0, dp1 = 0, 0
        hasZero = 0

        for ch in binary:
            if ch == '1':
                dp1 = (dp0 + dp1 + 1) % MOD
            else:  # ch == '0'
                dp0 = (dp0 + dp1) % MOD
                hasZero = 1  # at least one zero exists

        return (dp0 + dp1 + hasZero) % MOD
