class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        ans = 0

        for k in range(1, n + 1):
            if n % k != 0:
                continue

            valid = True

            for start in range(0, n, k):
                arr = nums[start:start + k]
                sorted_arr = sorted(arr)

                doubled = arr + arr
                found = False

                for i in range(k):
                    if doubled[i:i + k] == sorted_arr:
                        found = True
                        break

                if not found:
                    valid = False
                    break

            if valid:
                ans += k

        return ans
