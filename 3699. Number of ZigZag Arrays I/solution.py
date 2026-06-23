class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7
        m = r - l + 1

        # Length 2
        up = [0] * (m + 1)
        down = [0] * (m + 1)

        for v in range(1, m + 1):
            up[v] = v - 1          # previous value < v
            down[v] = m - v        # previous value > v

        for _ in range(3, n + 1):
            prefix_down = [0] * (m + 1)
            for v in range(1, m + 1):
                prefix_down[v] = (prefix_down[v - 1] + down[v]) % MOD

            suffix_up = [0] * (m + 2)
            for v in range(m, 0, -1):
                suffix_up[v] = (suffix_up[v + 1] + up[v]) % MOD

            new_up = [0] * (m + 1)
            new_down = [0] * (m + 1)

            for v in range(1, m + 1):
                new_up[v] = prefix_down[v - 1]      # previous value < v
                new_down[v] = suffix_up[v + 1]      # previous value > v

            up = new_up
            down = new_down

        return (sum(up) + sum(down)) % MOD
