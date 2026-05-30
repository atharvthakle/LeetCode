from typing import List
from bisect import bisect_left, bisect_right, insort

class SegmentTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (4 * n)

    def update(self, node, l, r, idx, val):
        if l == r:
            self.tree[node] = val
            return

        mid = (l + r) // 2

        if idx <= mid:
            self.update(node * 2, l, mid, idx, val)
        else:
            self.update(node * 2 + 1, mid + 1, r, idx, val)

        self.tree[node] = max(
            self.tree[node * 2],
            self.tree[node * 2 + 1]
        )

    def query(self, node, l, r, ql, qr):
        if ql > r or qr < l:
            return 0

        if ql <= l and r <= qr:
            return self.tree[node]

        mid = (l + r) // 2

        return max(
            self.query(node * 2, l, mid, ql, qr),
            self.query(node * 2 + 1, mid + 1, r, ql, qr)
        )


class Solution:
    def getResults(self, queries: List[List[int]]) -> List[bool]:
        MAXX = 50000

        obstacles = [0]
        st = SegmentTree(MAXX + 1)

        ans = []

        for q in queries:
            if q[0] == 1:
                x = q[1]

                pos = bisect_left(obstacles, x)

                left = obstacles[pos - 1]
                right = obstacles[pos] if pos < len(obstacles) else MAXX

                insort(obstacles, x)

                st.update(1, 0, MAXX, x, x - left)

                if right != MAXX:
                    st.update(1, 0, MAXX, right, right - x)

            else:
                _, x, sz = q

                pos = bisect_right(obstacles, x)
                last = obstacles[pos - 1]

                best = st.query(1, 0, MAXX, 0, last)

                tail = x - last

                ans.append(max(best, tail) >= sz)

        return ans
