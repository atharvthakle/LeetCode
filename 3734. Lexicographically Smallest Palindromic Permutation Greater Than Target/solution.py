class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        from collections import Counter

        n = len(s)
        freq = Counter(s)

        # A palindrome can have at most one character with odd frequency
        odd = [c for c, v in freq.items() if v % 2]
        if len(odd) > 1:
            return ""

        mid_char = odd[0] if odd else None
        half_cnt = [0] * 26

        for c, v in freq.items():
            half_cnt[ord(c) - 97] = v // 2

        mid = n // 2

        # Try to make the first differing position as far right as possible.
        # This gives the lexicographically smallest palindrome > target.
        for diff in range(n - 1, -1, -1):
            cnt = half_cnt[:]
            ans = [None] * n
            valid = True

            def assign(pos, ch):
                nonlocal valid

                mirror = n - 1 - pos

                if ans[pos] is not None:
                    if ans[pos] != ch:
                        valid = False
                    return

                if pos == mirror:
                    if mid_char != ch:
                        valid = False
                    else:
                        ans[pos] = ch
                    return

                idx = ord(ch) - 97
                if cnt[idx] == 0:
                    valid = False
                    return

                if ans[mirror] is not None and ans[mirror] != ch:
                    valid = False
                    return

                cnt[idx] -= 1
                ans[pos] = ch
                ans[mirror] = ch

            # Force all positions before diff to equal target
            for i in range(diff):
                assign(i, target[i])
                if not valid:
                    break

            if not valid:
                continue

            mirror = n - 1 - diff

            # Choose a character greater than target[diff]
            if ans[diff] is not None:
                if ans[diff] <= target[diff]:
                    continue
            else:
                chosen = None

                if diff == mirror:
                    if mid_char is not None and mid_char > target[diff]:
                        chosen = mid_char
                else:
                    start = ord(target[diff]) - 96
                    for x in range(start, 26):
                        if cnt[x] > 0:
                            chosen = chr(x + 97)
                            break

                if chosen is None:
                    continue

                assign(diff, chosen)

            if not valid:
                continue

            # Fill remaining palindrome positions with smallest possible chars
            for i in range(n // 2):
                if ans[i] is None:
                    for x in range(26):
                        if cnt[x] > 0:
                            ch = chr(x + 97)
                            cnt[x] -= 1
                            ans[i] = ch
                            ans[n - 1 - i] = ch
                            break

            if n % 2 == 1:
                ans[mid] = mid_char

            result = "".join(ans)

            if result > target:
                return result

        return ""
