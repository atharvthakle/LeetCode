from typing import List
import heapq

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        m = len(nums)
        n = m // 3

        # leftMin[i]: min sum of n elements chosen from nums[0..i]
        leftMin = [0] * m
        max_heap = []  # store negatives to simulate max-heap of size n (keeping n smallest)
        sum_small = 0

        for i in range(m):
            x = nums[i]
            heapq.heappush(max_heap, -x)
            sum_small += x
            if len(max_heap) > n:
                removed = -heapq.heappop(max_heap)  # remove largest among kept
                sum_small -= removed
            leftMin[i] = sum_small  # valid only when i >= n-1

        # rightMax[i]: max sum of n elements chosen from nums[i..m-1]
        rightMax = [0] * m
        min_heap = []  # min-heap of size n (keeping n largest)
        sum_large = 0

        for i in range(m - 1, -1, -1):
            x = nums[i]
            heapq.heappush(min_heap, x)
            sum_large += x
            if len(min_heap) > n:
                removed = heapq.heappop(min_heap)  # remove smallest among kept
                sum_large -= removed
            rightMax[i] = sum_large  # valid only when i <= 2n

        # Compute minimum difference using split between i and i+1
        ans = float('inf')
        for i in range(n - 1, 2 * n):
            # leftMin[i] is defined for i >= n-1
            # rightMax[i+1] is defined for i+1 <= 2n
            ans = min(ans, leftMin[i] - rightMax[i + 1])

        return ans
