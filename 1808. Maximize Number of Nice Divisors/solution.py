class Solution:
    def maxNiceDivisors(self, primeFactors: int) -> int:
        MOD = 10**9 + 7

        def power(x, y):
            result = 1
            x %= MOD
            while y > 0:
                if y & 1:
                    result = (result * x) % MOD
                x = (x * x) % MOD
                y >>= 1
            return result

        if primeFactors <= 3:
            return primeFactors

        # Break primeFactors into 3's as much as possible
        quotient, remainder = divmod(primeFactors, 3)

        if remainder == 0:
            return power(3, quotient) % MOD
        elif remainder == 1:
            return (power(3, quotient - 1) * 4) % MOD
        else:  # remainder == 2
            return (power(3, quotient) * 2) % MOD
