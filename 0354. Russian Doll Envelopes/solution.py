from bisect import bisect_left
from typing import List

class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        # Step 1: Sort envelopes
        # Ascending width, and if equal width -> descending height
        envelopes.sort(key=lambda x: (x[0], -x[1]))

        # Step 2: Extract heights
        heights = [h for _, h in envelopes]

        # Step 3: Find LIS on heights using binary search
        lis = []
        for h in heights:
            idx = bisect_left(lis, h)
            if idx == len(lis):
                lis.append(h)  # extend LIS
            else:
                lis[idx] = h   # replace to maintain smallest possible element

        return len(lis)
