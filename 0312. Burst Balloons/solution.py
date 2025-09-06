from typing import List
import functools

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)

        @functools.lru_cache(None)
        def dp(left, right):
            if left + 1 == right:
                return 0
            res = 0
            for k in range(left + 1, right):
                coins = nums[left] * nums[k] * nums[right]
                res = max(res, coins + dp(left, k) + dp(k, right))
            return res

        return dp(0, n - 1)
