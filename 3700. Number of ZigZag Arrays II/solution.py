class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7
        m = r - l + 1

        size = 2 * m

        # State:
        # 0..m-1      -> up[v]
        # m..2m-1     -> down[v]

        T = [[0] * size for _ in range(size)]

        # new_up[v] = sum(down[u]) for u < v
        for v in range(m):
            row = v
            for u in range(v):
                T[row][m + u] = 1

        # new_down[v] = sum(up[u]) for u > v
        for v in range(m):
            row = m + v
            for u in range(v + 1, m):
                T[row][u] = 1

        def mat_mul(A, B):
            n = len(A)
            C = [[0] * n for _ in range(n)]

            for i in range(n):
                Ai = A[i]
                Ci = C[i]
                for k in range(n):
                    if Ai[k] == 0:
                        continue
                    aik = Ai[k]
                    Bk = B[k]
                    for j in range(n):
                        if Bk[j]:
                            Ci[j] = (Ci[j] + aik * Bk[j]) % MOD
            return C

        def mat_pow(M, p):
            n = len(M)
            R = [[0] * n for _ in range(n)]
            for i in range(n):
                R[i][i] = 1

            while p:
                if p & 1:
                    R = mat_mul(R, M)
                M = mat_mul(M, M)
                p >>= 1

            return R

        def mat_vec_mul(M, vec):
            n = len(M)
            res = [0] * n

            for i in range(n):
                s = 0
                row = M[i]
                for j in range(n):
                    if row[j]:
                        s = (s + row[j] * vec[j]) % MOD
                res[i] = s

            return res

        # Length 2 base DP
        base = [0] * size

        for v in range(m):
            base[v] = v          # up[v]
            base[m + v] = m - 1 - v  # down[v]

        P = mat_pow(T, n - 2)
        state = mat_vec_mul(P, base)

        return sum(state) % MOD
