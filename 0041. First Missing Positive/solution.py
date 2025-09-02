class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        
        # Place each number in its correct position, i.e., nums[i] = i + 1
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i]-1] != nums[i]:
                # Swap nums[i] with the number at its target position
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        
        # Find the first index where the number is not correct
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        
        # If all numbers 1..n are present, the missing number is n+1
        return n + 1
