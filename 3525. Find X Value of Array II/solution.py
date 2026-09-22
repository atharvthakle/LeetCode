from typing import List

class Solution:
    def resultArray(self, nums: List[int], k: int, queries: List[List[int]]) -> List[int]:
        n = len(nums)
        size = 1
        while size < n:
            size <<= 1

        # Each node:
        # [product modulo k, prefix-product counts]
        prod = [1] * (2 * size)
        pref = [[0] * k for _ in range(2 * size)]

        def make_leaf(pos, val):
            p = val % k
            prod[pos] = p
            pref[pos][p] = 1

        for i in range(n):
            make_leaf(size + i, nums[i])

        def merge(pos):
            l = pos * 2
            r = l + 1

            lp = prod[l]
            prod[pos] = lp * prod[r] % k

            res = pref[pos]
            left = pref[l]
            right = pref[r]

            for x in range(k):
                res[x] = left[x]

            for x in range(k):
                if right[x]:
                    nx = lp * x % k
                    res[nx] += right[x]

        for i in range(size - 1, 0, -1):
            merge(i)

        def update(idx, val):
            p = size + idx

            pref[p] = [0] * k
            make_leaf(p, val)

            p >>= 1
            while p:
                merge(p)
                p >>= 1

        def query(l, r):
            # Returns product and prefix-product counts for [l, r)
            left_prod = 1
            left_pref = [0] * k

            right_prod = 1
            right_pref = [0] * k

            l += size
            r += size

            while l < r:
                if l & 1:
                    lp = left_prod
                    new_pref = left_pref[:]

                    for x in range(k):
                        if pref[l][x]:
                            nx = lp * x % k
                            new_pref[nx] += pref[l][x]

                    left_pref = new_pref
                    left_prod = lp * prod[l] % k
                    l += 1

                if r & 1:
                    r -= 1
                    rp = prod[r]
                    new_pref = pref[r][:]

                    for x in range(k):
                        if right_pref[x]:
                            nx = rp * x % k
                            new_pref[nx] += right_pref[x]

                    right_pref = new_pref
                    right_prod = rp * right_prod % k

                l >>= 1
                r >>= 1

            # Combine left and right
            ans_pref = left_pref[:]
            for x in range(k):
                if right_pref[x]:
                    nx = left_prod * x % k
                    ans_pref[nx] += right_pref[x]

            return left_prod * right_prod % k, ans_pref

        ans = []

        for index, value, start, x in queries:
            update(index, value)
            _, counts = query(start, n)
            ans.append(counts[x])

        return ans
