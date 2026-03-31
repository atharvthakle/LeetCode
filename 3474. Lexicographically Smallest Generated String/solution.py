class Solution:
    def generateString(self, str1: str, str2: str) -> str:
        n, m = len(str1), len(str2)
        size = n + m - 1

        word = ['?'] * size

        # Step 1: enforce T
        for i in range(n):
            if str1[i] == 'T':
                for j in range(m):
                    if word[i+j] == '?' or word[i+j] == str2[j]:
                        word[i+j] = str2[j]
                    else:
                        return ""

        # Step 2: fill remaining
        for i in range(size):
            if word[i] == '?':
                word[i] = 'a'

        # helper
        def is_match(start):
            for j in range(m):
                if word[start+j] != str2[j]:
                    return False
            return True

        # Step 3: fix F
        for i in range(n):
            if str1[i] == 'F' and is_match(i):
                fixed = False

                for j in range(m-1, -1, -1):
                    idx = i + j
                    original = word[idx]

                    for c in "abcdefghijklmnopqrstuvwxyz":
                        if c == original:
                            continue

                        word[idx] = c

                        # check ONLY affected T windows
                        ok = True
                        start = max(0, idx - m + 1)
                        end = min(n - 1, idx)

                        for k in range(start, end + 1):
                            if str1[k] == 'T' and not is_match(k):
                                ok = False
                                break

                        # also ensure current F is broken
                        if ok and not is_match(i):
                            fixed = True
                            break

                        word[idx] = original

                    if fixed:
                        break

                if not fixed:
                    return ""

        return "".join(word)
