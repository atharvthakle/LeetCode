class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        from math import factorial

        # list of numbers to pick from
        nums = [str(i) for i in range(1, n + 1)]
        k -= 1  # convert to 0-based index
        ans = []

        for i in range(n, 0, -1):
            fact = factorial(i - 1)
            index = k // fact
            ans.append(nums.pop(index))
            k %= fact

        return "".join(ans)
