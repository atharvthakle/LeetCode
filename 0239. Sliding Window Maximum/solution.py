from collections import deque
from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        if n == 0: 
            return []
        
        dq = deque()  # store indices of elements
        res = []

        for i in range(n):
            # Remove indices that are out of the current window
            while dq and dq[0] < i - k + 1:
                dq.popleft()

            # Remove indices whose corresponding values are less than nums[i]
            while dq and nums[dq[-1]] < nums[i]:
                dq.pop()

            dq.append(i)

            # Append the current max to the result starting from the first full window
            if i >= k - 1:
                res.append(nums[dq[0]])

        return res
