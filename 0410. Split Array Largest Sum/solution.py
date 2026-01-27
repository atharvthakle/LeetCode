class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        # Minimum possible max sum is max(nums)
        left = max(nums)
        # Maximum possible max sum is sum(nums)
        right = sum(nums)
        
        # Function to check if we can split into <= k subarrays
        # with each subarray sum <= mid
        def canSplit(mid):
            pieces = 1
            currSum = 0
            
            for num in nums:
                if currSum + num > mid:
                    pieces += 1
                    currSum = num
                    if pieces > k:
                        return False
                else:
                    currSum += num
            
            return True
        
        # Binary search for minimum feasible maximum sum
        while left < right:
            mid = (left + right) // 2
            if canSplit(mid):
                right = mid
            else:
                left = mid + 1
        
        return left
