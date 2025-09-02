class Solution:
    def minOperations(self, nums: List[int]) -> int:
        # Remove duplicates and sort
        unique_nums = sorted(set(nums))
        n = len(nums)
        ans = n
        
        j = 0
        for i in range(len(unique_nums)):
            # Expand the window to include as many numbers as possible within length n
            while j < len(unique_nums) and unique_nums[j] - unique_nums[i] < n:
                j += 1
            # Numbers inside the window: j - i
            ans = min(ans, n - (j - i))
        
        return ans
