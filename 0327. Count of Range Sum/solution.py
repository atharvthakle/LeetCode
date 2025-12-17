class Solution:
    def countRangeSum(self, nums, lower, upper):
        prefix = [0]
        for num in nums:
            prefix.append(prefix[-1] + num)

        def merge_sort(lo, hi):
            if hi - lo <= 1:
                return 0

            mid = (lo + hi) // 2
            count = merge_sort(lo, mid) + merge_sort(mid, hi)

            j = k = mid
            for i in range(lo, mid):
                while j < hi and prefix[j] - prefix[i] < lower:
                    j += 1
                while k < hi and prefix[k] - prefix[i] <= upper:
                    k += 1
                count += k - j

            prefix[lo:hi] = sorted(prefix[lo:hi])
            return count

        return merge_sort(0, len(prefix))
