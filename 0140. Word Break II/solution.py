from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        wordSet = set(wordDict)   # Faster lookup
        memo = {}  # Cache results for substrings

        def backtrack(start: int) -> List[str]:
            if start == len(s):
                return [""]  # End of string → return empty sentence
            
            if start in memo:
                return memo[start]

            sentences = []
            for end in range(start + 1, len(s) + 1):
                word = s[start:end]
                if word in wordSet:
                    rest_sentences = backtrack(end)
                    for rs in rest_sentences:
                        if rs:
                            sentences.append(word + " " + rs)
                        else:
                            sentences.append(word)

            memo[start] = sentences
            return sentences

        return backtrack(0)
