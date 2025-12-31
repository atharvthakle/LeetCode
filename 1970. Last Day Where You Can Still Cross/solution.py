class Solution:
    def latestDayToCross(self, row: int, col: int, cells: list[list[int]]) -> int:
        parent = list(range(row * col + 2))
        rank = [0] * (row * col + 2)

        TOP = row * col
        BOTTOM = row * col + 1

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            rx, ry = find(x), find(y)
            if rx == ry:
                return
            if rank[rx] < rank[ry]:
                parent[rx] = ry
            elif rank[rx] > rank[ry]:
                parent[ry] = rx
            else:
                parent[ry] = rx
                rank[rx] += 1

        grid = [[0] * col for _ in range(row)]
        directions = [(1,0), (-1,0), (0,1), (0,-1)]

        for day in range(len(cells) - 1, -1, -1):
            r, c = cells[day]
            r -= 1
            c -= 1
            grid[r][c] = 1
            idx = r * col + c

            if r == 0:
                union(idx, TOP)
            if r == row - 1:
                union(idx, BOTTOM)

            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < row and 0 <= nc < col and grid[nr][nc] == 1:
                    union(idx, nr * col + nc)

            if find(TOP) == find(BOTTOM):
                return day

        return 0
