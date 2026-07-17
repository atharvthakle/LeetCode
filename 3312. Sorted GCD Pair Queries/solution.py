from typing import List
from bisect import bisect_right

class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        mx = max(nums)

        freq = [0] * (mx + 1)
        for x in nums:
            freq[x] += 1

        # cnt[d] = how many numbers are divisible by d
        cnt = [0] * (mx + 1)
        for d in range(1, mx + 1):
            s = 0
            for m in range(d, mx + 1, d):
                s += freq[m]
            cnt[d] = s

        # exact[d] = number of pairs with gcd exactly d
        exact = [0] * (mx + 1)
        for d in range(mx, 0, -1):
            c = cnt[d]
            pairs = c * (c - 1) // 2
            m = d * 2
            while m <= mx:
                pairs -= exact[m]
                m += d
            exact[d] = pairs

        # prefix[g] = number of pairs with gcd <= g
        prefix = [0] * (mx + 1)
        for g in range(1, mx + 1):
            prefix[g] = prefix[g - 1] + exact[g]

        ans = []
        for q in queries:
            # first gcd value whose cumulative count exceeds q
            ans.append(bisect_right(prefix, q))
        return ans
