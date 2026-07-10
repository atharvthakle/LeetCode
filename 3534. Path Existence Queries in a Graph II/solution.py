class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        pairs = sorted((v, i) for i, v in enumerate(nums))
        vals = [v for v, _ in pairs]
        orig = [idx for _, idx in pairs]

        pos = [0] * n
        for i, idx in enumerate(orig):
            pos[idx] = i

        comp = [0] * n
        cid = 0
        for i in range(1, n):
            if vals[i] - vals[i - 1] > maxDiff:
                cid += 1
            comp[i] = cid

        nxt = [0] * n
        r = 0
        for l in range(n):
            while r + 1 < n and vals[r + 1] - vals[l] <= maxDiff:
                r += 1
            nxt[l] = r

        LOG = (n).bit_length()
        up = [nxt]
        for _ in range(1, LOG):
            prev = up[-1]
            cur = [0] * n
            for i in range(n):
                cur[i] = prev[prev[i]]
            up.append(cur)

        ans = []

        for u, v in queries:
            if u == v:
                ans.append(0)
                continue

            a = pos[u]
            b = pos[v]
            if a > b:
                a, b = b, a

            if comp[a] != comp[b]:
                ans.append(-1)
                continue

            cur = a
            steps = 0
            for k in range(LOG - 1, -1, -1):
                if up[k][cur] < b:
                    cur = up[k][cur]
                    steps += 1 << k

            ans.append(steps + 1)

        return ans
