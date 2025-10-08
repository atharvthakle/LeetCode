from math import gcd
from collections import defaultdict
from typing import List

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n <= 2:
            return n

        max_points = 0

        for i in range(n):
            slopes = defaultdict(int)
            duplicates = 0
            curr_max = 0
            x1, y1 = points[i]

            for j in range(i + 1, n):
                x2, y2 = points[j]
                dx, dy = x2 - x1, y2 - y1

                # duplicate point
                if dx == 0 and dy == 0:
                    duplicates += 1
                    continue

                # reduce by gcd
                g = gcd(dx, dy)
                if g != 0:
                    dx //= g
                    dy //= g

                # normalize:
                # - vertical lines -> (0, 1)
                # - horizontal lines -> (1, 0)
                # - otherwise ensure dx > 0 by flipping signs if needed
                if dx == 0:
                    dy = 1
                elif dy == 0:
                    dx = 1
                elif dx < 0:
                    dx, dy = -dx, -dy

                slopes[(dx, dy)] += 1
                curr_max = max(curr_max, slopes[(dx, dy)])

            # include the base point and any duplicates
            max_points = max(max_points, curr_max + duplicates + 1)

        return max_points
