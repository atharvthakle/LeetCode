from typing import List

class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        def steps_sum(l: int, r: int) -> int:
            """Return total required picks (sum of steps) for numbers in [l, r]."""
            total = 0
            t = 1
            base = 1  # 4^(t-1)
            # iterate while base <= r; base grows by *4 each time
            while base <= r:
                lo = base
                hi = base * 4 - 1
                if hi < l:
                    t += 1
                    base *= 4
                    continue
                if lo > r:
                    break
                left = max(l, lo)
                right = min(r, hi)
                if left <= right:
                    total += (right - left + 1) * t
                t += 1
                base *= 4
            return total

        ans = 0
        for l, r in queries:
            s = steps_sum(l, r)
            # each operation gives two picks, so ops = ceil(s/2)
            ops = (s + 1) // 2
            ans += ops
        return ans
