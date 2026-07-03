from typing import List
from collections import deque

class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)

        adj = [[] for _ in range(n)]
        indeg = [0] * n
        costs = []

        for u, v, w in edges:
            adj[u].append((v, w))
            indeg[v] += 1
            costs.append(w)

        # Topological order
        q = deque(i for i in range(n) if indeg[i] == 0)
        topo = []
        while q:
            u = q.popleft()
            topo.append(u)
            for v, _ in adj[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)

        if not costs:
            return -1

        costs = sorted(set(costs))

        INF = 10 ** 30

        def check(limit):
            dist = [INF] * n
            dist[0] = 0

            for u in topo:
                if dist[u] == INF:
                    continue
                if u != 0 and u != n - 1 and not online[u]:
                    continue

                for v, w in adj[u]:
                    if w < limit:
                        continue
                    if v != n - 1 and v != 0 and not online[v]:
                        continue
                    nd = dist[u] + w
                    if nd < dist[v]:
                        dist[v] = nd

            return dist[n - 1] <= k

        lo, hi = 0, len(costs) - 1
        ans = -1

        while lo <= hi:
            mid = (lo + hi) // 2
            if check(costs[mid]):
                ans = costs[mid]
                lo = mid + 1
            else:
                hi = mid - 1

        return ans
