from typing import List

class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.r = [0]*n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.r[pa] < self.r[pb]:
            pa, pb = pb, pa
        self.p[pb] = pa
        if self.r[pa] == self.r[pb]:
            self.r[pa] += 1
        return True


class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:

        def can(x):
            dsu = DSU(n)
            upgrades = 0
            used = 0

            # mandatory edges
            for u,v,s,m in edges:
                if m == 1:
                    if s < x:
                        return False
                    if not dsu.union(u,v):
                        return False
                    used += 1

            optional = []

            for u,v,s,m in edges:
                if m == 0:
                    optional.append((u,v,s))

            # first use edges without upgrade
            for u,v,s in optional:
                if s >= x and dsu.union(u,v):
                    used += 1

            # then try upgraded edges
            for u,v,s in optional:
                if s < x and 2*s >= x and upgrades < k:
                    if dsu.union(u,v):
                        upgrades += 1
                        used += 1

            return used == n-1


        left, right = 1, 2*10**5
        ans = -1

        while left <= right:
            mid = (left + right)//2
            if can(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1

        return ans
