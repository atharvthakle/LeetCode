from typing import List

class Solution:
    def longestCommonSubpath(self, n: int, paths: List[List[int]]) -> int:
        base = 10**5 + 7
        mod = (1 << 61) - 1  # large prime-like modulus for hashing
        
        # multiply with mod-safe technique
        def mul(a, b):
            return (a * b) % mod

        # rolling hash check for given length L
        def check(L):
            power = pow(base, L, mod)
            common = None

            for path in paths:
                h = 0
                s = set()
                for i, x in enumerate(path):
                    h = (mul(h, base) + x + 1) % mod
                    if i >= L:
                        h = (h - mul(path[i-L] + 1, power)) % mod
                    if i >= L - 1:
                        s.add(h)
                if common is None:
                    common = s
                else:
                    common &= s
                if not common:
                    return False
            return True

        # binary search on answer
        left, right = 0, min(len(p) for p in paths)
        ans = 0
        while left <= right:
            mid = (left + right) // 2
            if check(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans
