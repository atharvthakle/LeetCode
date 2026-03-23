class Solution:
    def largestPalindrome(self, n: int) -> int:
        if n == 1:
            return 9

        upper = 10**n - 1
        lower = 10**(n - 1)

        for left in range(upper, lower - 1, -1):
            # create palindrome
            s = str(left)
            pal = int(s + s[::-1])

            # check if pal = i * j
            for i in range(upper, int(pal**0.5) - 1, -1):
                if pal % i == 0:
                    j = pal // i
                    if lower <= j <= upper:
                        return pal % 1337

        return -1
