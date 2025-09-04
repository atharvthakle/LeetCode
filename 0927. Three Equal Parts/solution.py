from typing import List

class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        ones = sum(arr)
        n = len(arr)

        # Case 1: No 1's -> any valid partition works
        if ones == 0:
            return [0, n - 1]

        # Case 2: Not divisible by 3 -> impossible
        if ones % 3 != 0:
            return [-1, -1]

        k = ones // 3  # ones per part

        # find starting index of each part
        first = second = third = -1
        cnt = 0
        for i, bit in enumerate(arr):
            if bit == 1:
                cnt += 1
                if cnt == 1:
                    first = i
                elif cnt == k + 1:
                    second = i
                elif cnt == 2 * k + 1:
                    third = i
                    break

        # compare subarrays
        while third < n and arr[first] == arr[second] == arr[third]:
            first += 1
            second += 1
            third += 1

        if third == n:
            return [first - 1, second]
        return [-1, -1]
