from typing import List

class Solution:
    def maxValueAfterReverse(self, nums: List[int]) -> int:
        n = len(nums)
        orig = sum(abs(nums[i] - nums[i+1]) for i in range(n-1))
        max_gain = 0

        # Consider reversing subarray starting at 0 or ending at n-1
        for i in range(n-1):
            max_gain = max(max_gain,
                           abs(nums[i+1] - nums[0]) - abs(nums[i+1] - nums[i]),
                           abs(nums[i] - nums[-1]) - abs(nums[i+1] - nums[i]))

        # Consider internal subarrays
        min_mid, max_mid = float('inf'), float('-inf')
        for i in range(n-1):
            a, b = nums[i], nums[i+1]
            min_mid = min(min_mid, max(a, b))
            max_mid = max(max_mid, min(a, b))

        max_gain = max(max_gain, 2 * (max_mid - min_mid))

        return orig + max_gain
