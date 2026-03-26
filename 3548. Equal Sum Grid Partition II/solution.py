from typing import List
from collections import Counter

class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        total = sum(sum(row) for row in grid)

        # ---------- Helper: connectivity-aware removal ----------
        def can_remove_row(row, diff):
            return row[0] == diff or row[-1] == diff

        def can_remove_col(col_vals, diff):
            return col_vals[0] == diff or col_vals[-1] == diff

        # ---------- Horizontal Cuts ----------
        right = Counter()
        for row in grid:
            right.update(row)

        left = Counter()
        top_sum = 0

        for i in range(m - 1):
            for val in grid[i]:
                left[val] += 1
                right[val] -= 1
                if right[val] == 0:
                    del right[val]
                top_sum += val

            bottom_sum = total - top_sum

            if top_sum == bottom_sum:
                return True

            diff = abs(top_sum - bottom_sum)

            # remove from top
            if top_sum > bottom_sum:
                if diff in left:
                    rows = i + 1
                    if rows == 1:
                        if can_remove_row(grid[0], diff):
                            return True
                    elif n == 1:
                        col_vals = [grid[r][0] for r in range(rows)]
                        if can_remove_col(col_vals, diff):
                            return True
                    else:
                        return True

            # remove from bottom
            else:
                if diff in right:
                    rows = m - (i + 1)
                    if rows == 1:
                        if can_remove_row(grid[i+1], diff):
                            return True
                    elif n == 1:
                        col_vals = [grid[r][0] for r in range(i+1, m)]
                        if can_remove_col(col_vals, diff):
                            return True
                    else:
                        return True

        # ---------- Vertical Cuts ----------
        bottom = Counter()
        for row in grid:
            bottom.update(row)

        top = Counter()

        col_sums = [0] * n
        for j in range(n):
            for i in range(m):
                col_sums[j] += grid[i][j]

        left_sum = 0

        for j in range(n - 1):
            for i in range(m):
                val = grid[i][j]
                top[val] += 1
                bottom[val] -= 1
                if bottom[val] == 0:
                    del bottom[val]
                left_sum += val

            right_sum = total - left_sum

            if left_sum == right_sum:
                return True

            diff = abs(left_sum - right_sum)

            # remove from left
            if left_sum > right_sum:
                if diff in top:
                    cols = j + 1
                    if cols == 1:
                        col_vals = [grid[i][0] for i in range(m)]
                        if can_remove_col(col_vals, diff):
                            return True
                    elif m == 1:
                        if can_remove_row(grid[0][:j+1], diff):
                            return True
                    else:
                        return True

            # remove from right
            else:
                if diff in bottom:
                    cols = n - (j + 1)
                    if cols == 1:
                        col_vals = [grid[i][j+1] for i in range(m)]
                        if can_remove_col(col_vals, diff):
                            return True
                    elif m == 1:
                        if can_remove_row(grid[0][j+1:], diff):
                            return True
                    else:
                        return True

        return False
