class Solution:
    def processStr(self, s: str, k: int) -> str:
        LIMIT = 10**15

        n = len(s)
        length = [0] * (n + 1)

        for i, ch in enumerate(s):
            cur = length[i]

            if 'a' <= ch <= 'z':
                length[i + 1] = min(LIMIT + 1, cur + 1)
            elif ch == '*':
                length[i + 1] = max(0, cur - 1)
            elif ch == '#':
                length[i + 1] = min(LIMIT + 1, cur * 2)
            else:  # '%'
                length[i + 1] = cur

        if k >= length[n]:
            return '.'

        for i in range(n - 1, -1, -1):
            ch = s[i]
            prev_len = length[i]
            cur_len = length[i + 1]

            if 'a' <= ch <= 'z':
                if k == cur_len - 1:
                    return ch
                # otherwise k stays in the prefix

            elif ch == '*':
                # deletion of the last character; surviving indices unchanged
                pass

            elif ch == '#':
                if prev_len > 0 and k >= prev_len:
                    k -= prev_len

            else:  # '%'
                k = prev_len - 1 - k

        return '.'
