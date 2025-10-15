class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        MOD = 10**9 + 7
        N = 26  # letters a-z

        # Build transition matrix (26x26)
        M = [[0] * N for _ in range(N)]
        for i in range(N):
            for j in range(nums[i]):
                M[i][(i + j + 1) % N] = (M[i][(i + j + 1) % N] + 1) % MOD

        # Matrix multiplication
        def matmul(A, B):
            res = [[0] * N for _ in range(N)]
            for i in range(N):
                for k in range(N):
                    if A[i][k]:
                        for j in range(N):
                            res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD
            return res

        # Fast matrix exponentiation (M^t)
        def matpow(M, exp):
            res = [[1 if i == j else 0 for j in range(N)] for i in range(N)]
            while exp > 0:
                if exp % 2:
                    res = matmul(res, M)
                M = matmul(M, M)
                exp //= 2
            return res

        # Initial frequency vector of letters
        freq = [0] * N
        for c in s:
            freq[ord(c) - ord('a')] += 1

        # Compute M^t
        Mt = matpow(M, t)

        # Multiply Mt * freq to get final counts
        result = [0] * N
        for i in range(N):
            for j in range(N):
                result[i] = (result[i] + Mt[j][i] * freq[j]) % MOD

        # Sum total characters
        return sum(result) % MOD
