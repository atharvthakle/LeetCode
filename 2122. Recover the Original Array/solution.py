from typing import List
from collections import Counter

class Solution:
    def recoverArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums) // 2
        freq = Counter(nums)

        for j in range(1, len(nums)):
            # candidate k = difference between two numbers divided by 2
            diff = nums[j] - nums[0]
            if diff % 2 != 0 or diff == 0:
                continue
            k = diff // 2
            counter = Counter(nums)
            res = []
            for num in sorted(counter):
                while counter[num] > 0:
                    # pick lower = num, higher = num + 2*k
                    lower = num
                    higher = lower + 2 * k
                    if counter[higher] <= 0:
                        break
                    res.append(lower + k)
                    counter[lower] -= 1
                    counter[higher] -= 1
            if len(res) == n:
                return res
        return []
