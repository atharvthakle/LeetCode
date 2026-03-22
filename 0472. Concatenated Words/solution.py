from typing import List

class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        words.sort(key=len)
        word_set = set()
        result = []

        def canForm(word):
            if not word_set:
                return False
            
            dp = [False] * (len(word) + 1)
            dp[0] = True

            for i in range(1, len(word) + 1):
                for j in range(i):
                    if dp[j] and word[j:i] in word_set:
                        dp[i] = True
                        break

            return dp[len(word)]

        for word in words:
            if canForm(word):
                result.append(word)
            word_set.add(word)

        return result
