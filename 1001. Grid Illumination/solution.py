class Solution:
    def gridIllumination(self, n: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        from collections import defaultdict

        rows = defaultdict(int)
        cols = defaultdict(int)
        diag1 = defaultdict(int)  # r - c
        diag2 = defaultdict(int)  # r + c
        lamp_set = set()

        # Initialize lamp positions
        for r, c in lamps:
            if (r, c) not in lamp_set:
                lamp_set.add((r, c))
                rows[r] += 1
                cols[c] += 1
                diag1[r - c] += 1
                diag2[r + c] += 1

        res = []
        directions = [(0,0),(0,1),(0,-1),(1,0),(-1,0),(1,1),(1,-1),(-1,1),(-1,-1)]

        for r, c in queries:
            # Check if illuminated
            if rows[r] > 0 or cols[c] > 0 or diag1[r - c] > 0 or diag2[r + c] > 0:
                res.append(1)
            else:
                res.append(0)

            # Turn off lamp at (r,c) and its adjacent cells
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if (nr, nc) in lamp_set:
                    lamp_set.remove((nr, nc))
                    rows[nr] -= 1
                    cols[nc] -= 1
                    diag1[nr - nc] -= 1
                    diag2[nr + nc] -= 1

        return res
