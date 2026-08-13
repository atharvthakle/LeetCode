class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
        n = len(s)
        arr = list(s)

        size = 1
        while size < n:
            size *= 2

        seg = [0] * (2 * size)

        for i in range(n):
            seg[size + i] = 1

        for i in range(size - 1, 0, -1):
            seg[i] = max(seg[2 * i], seg[2 * i + 1])

        # We maintain runs of equal characters using a segment tree.
        # Each node stores:
        # left character, right character,
        # longest prefix, longest suffix, longest run.
        left_char = [''] * (2 * size)
        right_char = [''] * (2 * size)
        prefix = [0] * (2 * size)
        suffix = [0] * (2 * size)
        best = [0] * (2 * size)
        length = [0] * (2 * size)

        for i in range(n):
            p = size + i
            left_char[p] = right_char[p] = arr[i]
            prefix[p] = suffix[p] = best[p] = length[p] = 1

        def merge(p):
            a = p * 2
            b = a + 1

            if length[a] == 0:
                left_char[p] = left_char[b]
                right_char[p] = right_char[b]
                prefix[p] = prefix[b]
                suffix[p] = suffix[b]
                best[p] = best[b]
                length[p] = length[b]
                return

            if length[b] == 0:
                left_char[p] = left_char[a]
                right_char[p] = right_char[a]
                prefix[p] = prefix[a]
                suffix[p] = suffix[a]
                best[p] = best[a]
                length[p] = length[a]
                return

            length[p] = length[a] + length[b]
            left_char[p] = left_char[a]
            right_char[p] = right_char[b]

            prefix[p] = prefix[a]
            if prefix[a] == length[a] and right_char[a] == left_char[b]:
                prefix[p] += prefix[b]

            suffix[p] = suffix[b]
            if suffix[b] == length[b] and right_char[a] == left_char[b]:
                suffix[p] += suffix[a]

            best[p] = max(best[a], best[b])

            if right_char[a] == left_char[b]:
                best[p] = max(best[p], suffix[a] + prefix[b])

        for p in range(size - 1, 0, -1):
            merge(p)

        def update(pos, ch):
            arr[pos] = ch
            p = size + pos

            left_char[p] = right_char[p] = ch
            prefix[p] = suffix[p] = best[p] = length[p] = 1

            p //= 2
            while p:
                merge(p)
                p //= 2

        ans = []

        for ch, idx in zip(queryCharacters, queryIndices):
            if arr[idx] != ch:
                update(idx, ch)

            ans.append(best[1])

        return ans
