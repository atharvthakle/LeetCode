from typing import List
from bisect import bisect_left, bisect_right

class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        if not nums:
            return 0
        nums.sort()
        n = len(nums)
        
        # Build interval endpoints
        starts = [x - k for x in nums]
        ends   = [x + k for x in nums]
        starts.sort()
        ends.sort()
        
        # Compute maximum overlap across all T (sweep using starts/ends)
        i = j = 0
        cur = 0
        maxOverlap = 0
        while i < n and j < n:
            if starts[i] <= ends[j]:
                cur += 1
                if cur > maxOverlap:
                    maxOverlap = cur
                i += 1
            else:
                cur -= 1
                j += 1
        # No need to continue after i exhausted; maxOverlap already captured.
        
        ans = 0
        # Candidate from T not equal to any nums value:
        # we can convert at most numOperations elements to such a T
        if numOperations > 0:
            ans = min(maxOverlap, numOperations)
        
        # Evaluate f(v) for each distinct value v in nums
        idx = 0
        while idx < n:
            v = nums[idx]
            # count eq(v) (consecutive equal values because sorted)
            start_idx = idx
            while idx < n and nums[idx] == v:
                idx += 1
            eq = idx - start_idx
            
            # total intervals containing v = (#starts <= v) - (#ends < v)
            cntStartLE = bisect_right(starts, v)      # starts <= v
            cntEndLT   = bisect_left(ends, v)         # ends < v
            total_in_interval = cntStartLE - cntEndLT
            
            candidate = min(total_in_interval, eq + numOperations)
            if candidate > ans:
                ans = candidate
        
        return ans
