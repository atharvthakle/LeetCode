from typing import List

class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        n = len(nums)
        ops = 0
        prev = nums[-1]  # smallest allowed value from right
        
        for i in range(n - 2, -1, -1):
            if nums[i] <= prev:
                prev = nums[i]
            else:
                # number of parts needed
                parts = (nums[i] + prev - 1) // prev  # ceil division
                ops += parts - 1
                prev = nums[i] // parts  # update new allowed max
        
        return ops
