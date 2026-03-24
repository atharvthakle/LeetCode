class Solution:
    def smallestGoodBase(self, n: str) -> str:
        n = int(n)

        # maximum length of representation
        max_m = n.bit_length()  # approx log2(n)

        # try lengths from largest to smallest
        for m in range(max_m, 1, -1):
            left, right = 2, int(n ** (1 / (m - 1))) + 1

            while left <= right:
                k = (left + right) // 2

                # compute geometric sum: 1 + k + k^2 + ... + k^(m-1)
                total = 1
                curr = 1

                for _ in range(1, m):
                    curr *= k
                    total += curr
                    if total > n:
                        break

                if total == n:
                    return str(k)
                elif total < n:
                    left = k + 1
                else:
                    right = k - 1

        # fallback: base = n-1 → always "11"
        return str(n - 1)
