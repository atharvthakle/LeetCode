from bisect import bisect_left, insort

class Solution:
    def maxSumSubmatrix(self, matrix, k):
        rows, cols = len(matrix), len(matrix[0])
        ans = float('-inf')

        # Optimize by iterating over smaller dimension
        if rows > cols:
            matrix = list(zip(*matrix))
            rows, cols = cols, rows

        for left in range(cols):
            row_sums = [0] * rows
            for right in range(left, cols):
                for r in range(rows):
                    row_sums[r] += matrix[r][right]

                # Find max subarray sum <= k
                prefix_sum = 0
                prefix_sums = [0]
                curr_max = float('-inf')

                for val in row_sums:
                    prefix_sum += val
                    # We want smallest prefix >= prefix_sum - k
                    idx = bisect_left(prefix_sums, prefix_sum - k)
                    if idx < len(prefix_sums):
                        curr_max = max(curr_max, prefix_sum - prefix_sums[idx])
                    insort(prefix_sums, prefix_sum)

                ans = max(ans, curr_max)

        return ans
