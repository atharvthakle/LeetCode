class Solution:
    def palindromePath(self, n: int, edges: list[list[int]], s: str, queries: list[str]) -> list[bool]:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        LOG = n.bit_length()
        parent = [-1] * n
        depth = [0] * n
        tin = [0] * n
        tout = [0] * n
        initial_prefix = [0] * n
        timer = 0

        stack = [(0, -1, 0)]
        while stack:
            u, p, state = stack.pop()

            if state == 0:
                parent[u] = p
                tin[u] = timer
                timer += 1

                bit = 1 << (ord(s[u]) - ord('a'))
                initial_prefix[u] = (initial_prefix[p] if p != -1 else 0) ^ bit

                stack.append((u, p, 1))
                for v in reversed(adj[u]):
                    if v != p:
                        depth[v] = depth[u] + 1
                        stack.append((v, u, 0))
            else:
                tout[u] = timer - 1

        up = [[-1] * n for _ in range(LOG)]
        up[0] = parent[:]

        for j in range(1, LOG):
            prev = up[j - 1]
            curr = up[j]
            for u in range(n):
                p = prev[u]
                if p != -1:
                    curr[u] = prev[p]

        def lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u

            diff = depth[u] - depth[v]
            bit = 0
            while diff:
                if diff & 1:
                    u = up[bit][u]
                diff >>= 1
                bit += 1

            if u == v:
                return u

            for j in range(LOG - 1, -1, -1):
                if up[j][u] != up[j][v]:
                    u = up[j][u]
                    v = up[j][v]

            return parent[u]

        fenwick = [0] * (n + 2)

        def add(idx, val):
            idx += 1
            while idx <= n + 1:
                fenwick[idx] ^= val
                idx += idx & -idx

        def range_xor(left, right, val):
            add(left, val)
            if right + 1 < n:
                add(right + 1, val)

        def point_query(idx):
            idx += 1
            result = 0
            while idx > 0:
                result ^= fenwick[idx]
                idx -= idx & -idx
            return result

        chars = list(s)
        ans = []

        for q in queries:
            parts = q.split()

            if parts[0] == "update":
                u = int(parts[1])
                c = parts[2]

                if chars[u] != c:
                    delta = (1 << (ord(chars[u]) - ord('a'))) ^ (1 << (ord(c) - ord('a')))
                    range_xor(tin[u], tout[u], delta)
                    chars[u] = c
            else:
                u, v = int(parts[1]), int(parts[2])
                w = lca(u, v)

                pu = initial_prefix[u] ^ point_query(tin[u])
                pv = initial_prefix[v] ^ point_query(tin[v])
                bit_w = 1 << (ord(chars[w]) - ord('a'))

                mask = pu ^ pv ^ bit_w
                ans.append((mask & (mask - 1)) == 0)

        return ans
