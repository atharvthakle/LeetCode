class Solution:
    def numDecodings(self, s: str) -> int:
        MOD = 10**9 + 7
        n = len(s)
        if not s: 
            return 0
        
        dp0, dp1 = 1, 0  # dp0 = dp[i-2], dp1 = dp[i-1]
        
        # Initialize for the first character
        if s[0] == '*':
            dp1 = 9
        elif s[0] != '0':
            dp1 = 1
        else:
            dp1 = 0
        
        for i in range(1, n):
            dp2 = 0
            # Single digit
            if s[i] == '*':
                dp2 += 9 * dp1
            elif s[i] != '0':
                dp2 += dp1
            # Two digits
            if s[i-1] == '*' and s[i] == '*':
                # 11-19 and 21-26
                dp2 += 15 * dp0  # 9 + 6
            elif s[i-1] == '*':
                if '0' <= s[i] <= '6':
                    dp2 += 2 * dp0  # 1x and 2x
                else:
                    dp2 += dp0      # only 1x
            elif s[i] == '*':
                if s[i-1] == '1':
                    dp2 += 9 * dp0
                elif s[i-1] == '2':
                    dp2 += 6 * dp0
            else:
                if s[i-1] != '0' and 10 <= int(s[i-1:i+1]) <= 26:
                    dp2 += dp0
            dp0, dp1 = dp1, dp2 % MOD
        
        return dp1
