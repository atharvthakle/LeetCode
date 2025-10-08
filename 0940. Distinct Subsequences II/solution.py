class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10**9 + 7
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1  # empty subsequence

        last = {}  # last occurrence of each character

        for i in range(1, n + 1):
            c = s[i-1]
            dp[i] = (2 * dp[i-1]) % MOD
            if c in last:
                dp[i] = (dp[i] - dp[last[c]-1] + MOD) % MOD
            last[c] = i

        return (dp[n] - 1) % MOD
