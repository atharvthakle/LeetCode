class WordFilter:
    def __init__(self, words: List[str]):
        # Map all prefix#suffix combinations to the latest index
        self.lookup = {}
        for index, word in enumerate(words):
            L = len(word)
            # Generate all possible prefix and suffix combinations
            for i in range(L + 1):
                prefix = word[:i]
                for j in range(L + 1):
                    suffix = word[L-j:]
                    key = prefix + '#' + suffix
                    self.lookup[key] = index

    def f(self, pref: str, suff: str) -> int:
        return self.lookup.get(pref + '#' + suff, -1)
