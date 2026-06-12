from typing import List
from collections import deque

class Solution:
    def assignEdgeWeights(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(edges) + 1

        g = [[] for _ in range(n + 1)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        LOG = (n + 1).bit_length()

        depth = [0] * (n + 1)
        parent = [[0] * (n + 1) for _ in range(LOG)]

        q = deque([1])
        visited = [False] * (n + 1)
        visited[1] = True

        while q:
            u = q.popleft()
            for v in g[u]:
                if not visited[v]:
                    visited[v] = True
                    depth[v] = depth[u] + 1
                    parent[0][v] = u
                    q.append(v)

        for k in range(1, LOG):
            for v in range(1, n + 1):
                parent[k][v] = parent[k - 1][parent[k - 1][v]]

        def lca(a, b):
            if depth[a] < depth[b]:
                a, b = b, a

            diff = depth[a] - depth[b]
            bit = 0
            while diff:
                if diff & 1:
                    a = parent[bit][a]
                diff >>= 1
                bit += 1

            if a == b:
                return a

            for k in range(LOG - 1, -1, -1):
                if parent[k][a] != parent[k][b]:
                    a = parent[k][a]
                    b = parent[k][b]

            return parent[0][a]

        # Maximum possible path length is n-1
        pow2 = [1] * n
        for i in range(1, n):
            pow2[i] = (pow2[i - 1] * 2) % MOD

        ans = []

        for u, v in queries:
            w = lca(u, v)
            path_len = depth[u] + depth[v] - 2 * depth[w]

            if path_len == 0:
                ans.append(0)
            else:
                ans.append(pow2[path_len - 1])

        return ans
