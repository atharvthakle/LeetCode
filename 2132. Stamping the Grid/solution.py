class Solution:
    def possibleToStamp(self, grid: List[List[int]], stampHeight: int, stampWidth: int) -> bool:
        m, n = len(grid), len(grid[0])

        # Step 1: Build prefix sum of occupied cells (1s)
        pre = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            for j in range(n):
                pre[i + 1][j + 1] = grid[i][j] + pre[i][j + 1] + pre[i + 1][j] - pre[i][j]

        # Step 2: Helper to check if a rectangle is all zeros
        def can_stamp(i, j):
            x2, y2 = i + stampHeight, j + stampWidth
            if x2 > m or y2 > n:
                return False
            total = pre[x2][y2] - pre[i][y2] - pre[x2][j] + pre[i][j]
            return total == 0  # all empty

        # Step 3: Create a diff matrix to mark stamp coverage efficiently
        diff = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m):
            for j in range(n):
                if can_stamp(i, j):
                    diff[i][j] += 1
                    diff[i + stampHeight][j] -= 1
                    diff[i][j + stampWidth] -= 1
                    diff[i + stampHeight][j + stampWidth] += 1

        # Step 4: Prefix sum over diff to find which cells are covered
        for i in range(m):
            for j in range(n):
                diff[i][j] += (diff[i - 1][j] if i > 0 else 0) + (diff[i][j - 1] if j > 0 else 0) - (diff[i - 1][j - 1] if i > 0 and j > 0 else 0)

        # Step 5: Verify all empty cells are covered
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and diff[i][j] == 0:
                    return False
        return True
