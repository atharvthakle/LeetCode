from typing import List

class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        size = 1
        while size < n:
            size <<= 1

        tree = [0] * (2 * size)
        lazy = [0] * (2 * size)
        sum_sq = [0] * (2 * size)

        def apply(node, l, r, val):
            length = r - l + 1
            sum_sq[node] = (sum_sq[node] + 2 * val * tree[node] + length * val * val) % MOD
            tree[node] = (tree[node] + length * val) % MOD
            lazy[node] = (lazy[node] + val) % MOD

        def push(node, l, r):
            if lazy[node] == 0 or l == r:
                return
            mid = (l + r) // 2
            apply(node * 2, l, mid, lazy[node])
            apply(node * 2 + 1, mid + 1, r, lazy[node])
            lazy[node] = 0

        def update(node, l, r, ql, qr, val):
            if ql <= l and r <= qr:
                apply(node, l, r, val)
                return
            push(node, l, r)
            mid = (l + r) // 2
            if ql <= mid:
                update(node * 2, l, mid, ql, qr, val)
            if qr > mid:
                update(node * 2 + 1, mid + 1, r, ql, qr, val)
            tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD
            sum_sq[node] = (sum_sq[node * 2] + sum_sq[node * 2 + 1]) % MOD

        last = {}
        ans = 0

        for i, x in enumerate(nums):
            left = last.get(x, -1) + 1
            update(1, 0, size - 1, left, i, 1)
            ans = (ans + sum_sq[1]) % MOD
            last[x] = i

        return ans`
