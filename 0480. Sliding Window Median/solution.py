from sortedcontainers import SortedList

class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        window = SortedList()
        res = []

        for i, num in enumerate(nums):
            window.add(num)
            if i >= k:
                window.remove(nums[i - k])
            if i >= k - 1:
                if k % 2 == 1:
                    res.append(float(window[k // 2]))
                else:
                    res.append((window[k // 2 - 1] + window[k // 2]) / 2)

        return res
