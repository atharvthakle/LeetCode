from collections import Counter
from math import comb

class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        CAP = k

        freq = Counter(s)
        half = [0] * 26
        mid = ""

        for i in range(26):
            c = chr(ord('a') + i)
            half[i] = freq[c] // 2
            if freq[c] % 2:
                mid = c

        def count_perms(cnt):
            rem = sum(cnt)
            res = 1
            for x in cnt:
                if x:
                    res *= comb(rem, x)
                    if res >= CAP:
                        return CAP
                    rem -= x
            return res

        if count_perms(half) < k:
            return ""

        left = []

        for _ in range(sum(half)):
            for i in range(26):
                if half[i] == 0:
                    continue
                half[i] -= 1
                ways = count_perms(half)
                if ways >= k:
                    left.append(chr(ord('a') + i))
                    break
                k -= ways
                half[i] += 1

        left = "".join(left)
        return left + mid + left[::-1]
