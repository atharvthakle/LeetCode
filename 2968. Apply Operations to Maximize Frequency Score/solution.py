class Solution:
    def maxFrequencyScore(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        # prefix sums: pref[i] = sum of nums[0..i-1]
        pref = [0] * (n + 1)
        for i in range(n):
            pref[i+1] = pref[i] + nums[i]

        def cost_to_make_all_equal_to_median(l: int, r: int) -> int:
            """
            Return minimal operations to make nums[l..r] all equal to nums[m],
            where m = (l + r) // 2 (median index).
            """
            m = (l + r) // 2
            # sum of left part nums[l..m-1]
            left_sum = pref[m] - pref[l]
            left_count = m - l
            left_cost = nums[m] * left_count - left_sum

            # sum of right part nums[m+1..r]
            right_sum = pref[r+1] - pref[m+1]
            right_count = r - m
            right_cost = right_sum - nums[m] * right_count

            return left_cost + right_cost

        res = 1
        l = 0
        for r in range(n):
            # shrink from left until cost <= k
            while l <= r and cost_to_make_all_equal_to_median(l, r) > k:
                l += 1
            res = max(res, r - l + 1)

        return res
