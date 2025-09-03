class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        word_to_index = {w: i for i, w in enumerate(words)}  # map word → index
        res = []

        def is_palindrome(check: str) -> bool:
            return check == check[::-1]

        for i, word in enumerate(words):
            n = len(word)
            for cut in range(n + 1):
                prefix, suffix = word[:cut], word[cut:]

                # Case 1: prefix is palindrome -> need reversed suffix
                if is_palindrome(prefix):
                    back = suffix[::-1]
                    if back in word_to_index and word_to_index[back] != i:
                        res.append([word_to_index[back], i])

                # Case 2: suffix is palindrome -> need reversed prefix
                # (avoid duplicate when cut == n, because suffix == "")
                if cut != n and is_palindrome(suffix):
                    back = prefix[::-1]
                    if back in word_to_index and word_to_index[back] != i:
                        res.append([i, word_to_index[back]])

        return res
