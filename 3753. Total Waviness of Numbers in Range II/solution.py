from functools import lru_cache

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        def solve(n: int) -> int:
            if n <= 0:
                return 0

            s = str(n)

            @lru_cache(None)
            def dp(pos, tight, started, prev1, prev2, length):
                if pos == len(s):
                    return (1, 0)  # (count, total_waviness)

                limit = int(s[pos]) if tight else 9

                total_count = 0
                total_wavy = 0

                for d in range(limit + 1):
                    ntight = tight and (d == limit)

                    if not started and d == 0:
                        cnt, wav = dp(
                            pos + 1,
                            ntight,
                            False,
                            0,
                            0,
                            0
                        )
                        total_count += cnt
                        total_wavy += wav
                    else:
                        if not started:
                            cnt, wav = dp(
                                pos + 1,
                                ntight,
                                True,
                                d,
                                0,
                                1
                            )
                            total_count += cnt
                            total_wavy += wav
                        else:
                            add = 0

                            if length >= 2:
                                middle = prev1
                                left = prev2
                                right = d

                                if ((middle > left and middle > right) or
                                    (middle < left and middle < right)):
                                    add = 1

                            cnt, wav = dp(
                                pos + 1,
                                ntight,
                                True,
                                d,
                                prev1,
                                min(length + 1, 16)
                            )

                            total_count += cnt
                            total_wavy += wav + cnt * add

                return (total_count, total_wavy)

            return dp(0, True, False, 0, 0, 0)[1]

        return solve(num2) - solve(num1 - 1)
