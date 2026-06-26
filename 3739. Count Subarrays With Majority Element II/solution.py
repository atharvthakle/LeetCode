from typing import List

class Fenwick:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 2)

    def update(self, i, delta):
        while i <= self.n:
            self.bit[i] += delta
            i += i & -i

    def query(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s


class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        offset = n + 1
        size = 2 * n + 3

        bit = Fenwick(size)

        prefix = 0
        ans = 0

        # Initial prefix sum = 0
        bit.update(offset, 1)

        for x in nums:
            if x == target:
                prefix += 1
            else:
                prefix -= 1

            idx = prefix + offset
            ans += bit.query(idx - 1)   # previous prefix sums < current prefix
            bit.update(idx, 1)

        return ans
