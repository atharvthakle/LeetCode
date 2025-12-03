from typing import List
from collections import defaultdict
import math

class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        MOD = 10**9 + 7
        n = len(points)
        if n < 4:
            return 0

        # 1) Build lines grouped by slope.
        # lines_by_slope[(dy, dx)][c] = set of point indices on that line,
        # where c = dx * y - dy * x (line invariant for direction (dx, dy)).
        lines_by_slope: dict = defaultdict(lambda: defaultdict(set))

        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                dx = x2 - x1
                dy = y2 - y1
                g = math.gcd(dx, dy)
                dx //= g
                dy //= g

                # Canonicalize direction: make (dx, dy) unique sign
                if dx < 0 or (dx == 0 and dy < 0):
                    dx = -dx
                    dy = -dy

                slope = (dy, dx)
                # line constant: dx*y - dy*x is invariant along line with direction (dx, dy)
                c = dx * y1 - dy * x1
                lines_by_slope[slope][c].add(i)
                lines_by_slope[slope][c].add(j)

        # 2) Count trapezoids (possibly counting parallelograms twice).
        trapezoid_total = 0

        for slope, lines in lines_by_slope.items():
            # For each line with >=2 points, we have C(cnt,2) possible "side" segments.
            side_counts = []
            for pts in lines.values():
                cnt = len(pts)
                if cnt >= 2:
                    side_counts.append(cnt * (cnt - 1) // 2)

            if len(side_counts) >= 2:
                ssum = sum(side_counts)
                sqsum = sum(a * a for a in side_counts)
                # sum_{i<j} a_i * a_j = ( (sum a_i)^2 - sum a_i^2 ) / 2
                val = (ssum * ssum - sqsum) // 2
                trapezoid_total = (trapezoid_total + val) % MOD

        # 3) Count ALL parallelograms via midpoint trick
        midpoint_count = defaultdict(int)
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                key = (x1 + x2, y1 + y2)  # midpoint * 2
                midpoint_count[key] += 1

        total_parallelograms = 0
        for c in midpoint_count.values():
            if c >= 2:
                total_parallelograms += c * (c - 1) // 2

        # 4) Subtract degenerate parallelograms (where all 4 points are collinear)
        degenerate_parallelograms = 0
        for (dy, dx), lines in lines_by_slope.items():
            for c, pts in lines.items():
                if len(pts) < 4:
                    continue
                idx_list = list(pts)
                # Use x if line not vertical; otherwise use y
                use_x = (dx != 0)
                coords = [points[i][0] if use_x else points[i][1] for i in idx_list]

                sum_counts = defaultdict(int)
                m = len(coords)
                for i in range(m):
                    ci = coords[i]
                    for j in range(i + 1, m):
                        s = ci + coords[j]
                        sum_counts[s] += 1

                for f in sum_counts.values():
                    if f >= 2:
                        degenerate_parallelograms += f * (f - 1) // 2

        valid_parallelograms = total_parallelograms - degenerate_parallelograms
        if valid_parallelograms < 0:
            valid_parallelograms = 0  # safety, though it shouldn't happen

        # 5) Each parallelogram was counted twice in trapezoid_total; subtract once
        ans = (trapezoid_total - valid_parallelograms) % MOD
        return ans
