class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)

        values = {x: i for i, x in enumerate(sorted(set(nums)))}
        rank = [values[x] for x in nums]

        sa = list(range(n))
        k = 1

        while k < n:
            sa.sort(key=lambda i: (rank[i], rank[i + k] if i + k < n else -1))

            new_rank = [0] * n
            for i in range(1, n):
                a, b = sa[i - 1], sa[i]
                prev = (rank[a], rank[a + k] if a + k < n else -1)
                curr = (rank[b], rank[b + k] if b + k < n else -1)
                new_rank[b] = new_rank[a] + (prev != curr)

            rank = new_rank
            if rank[sa[-1]] == n - 1:
                break
            k *= 2

        pos = [0] * n
        for i, suffix in enumerate(sa):
            pos[suffix] = i

        lcp = [0] * n
        h = 0

        for i in range(n):
            r = pos[i]
            if r == 0:
                h = 0
                continue

            j = sa[r - 1]
            while i + h < n and j + h < n and nums[i + h] == nums[j + h]:
                h += 1

            lcp[r] = h
            if h:
                h -= 1

        ans = n

        for i in range(n):
            r = pos[i]
            max_lcp = lcp[r]

            if r + 1 < n:
                max_lcp = max(max_lcp, lcp[r + 1])

            suffix_length = n - i

            if max_lcp < suffix_length:
                ans = min(ans, max_lcp + 1)

        return ans
