class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)

        arr = sorted(
            [(l, r, w, i) for i, (l, r, w) in enumerate(intervals)],
            key=lambda x: (x[0], x[1], x[3])
        )

        # next[i] = first interval whose left endpoint > arr[i].right
        import bisect

        starts = [x[0] for x in arr]
        nxt = [
            bisect.bisect_right(starts, arr[i][1])
            for i in range(n)
        ]

        # dp[i][k] = best (weight, indices) using intervals from i onward,
        # choosing at most k intervals.
        dp = [[(0, ()) for _ in range(5)] for _ in range(n + 1)]

        def better(a, b):
            if a[0] != b[0]:
                return a if a[0] > b[0] else b
            return a if a[1] < b[1] else b

        for i in range(n - 1, -1, -1):
            for k in range(1, 5):
                skip = dp[i + 1][k]

                take_rest = dp[nxt[i]][k - 1]
                take = (
                    arr[i][2] + take_rest[0],
                    tuple(sorted((arr[i][3],) + take_rest[1]))
                )

                dp[i][k] = better(skip, take)

            dp[i][0] = (0, ())

        return list(dp[0][4][1])
