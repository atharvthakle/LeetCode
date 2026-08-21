class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        from math import gcd

        def lcm(a, b):
            return a // gcd(a, b) * b

        def count(x):
            total = 0
            n = len(coins)

            for mask in range(1, 1 << n):
                mult = 1
                bits = 0
                valid = True

                for i in range(n):
                    if mask & (1 << i):
                        bits += 1
                        mult = lcm(mult, coins[i])

                        if mult > x:
                            valid = False
                            break

                if valid:
                    if bits & 1:
                        total += x // mult
                    else:
                        total -= x // mult

            return total

        lo = 1
        hi = min(coins) * k

        while lo < hi:
            mid = (lo + hi) // 2

            if count(mid) >= k:
                hi = mid
            else:
                lo = mid + 1

        return lo
