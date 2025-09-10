from collections import deque
from typing import List

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0
        
        queue = deque([(beginWord, 1)])  # (current_word, current_length)
        L = len(beginWord)
        
        while queue:
            word, length = queue.popleft()
            if word == endWord:
                return length
            for i in range(L):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    nextWord = word[:i] + c + word[i+1:]
                    if nextWord in wordSet:
                        wordSet.remove(nextWord)
                        queue.append((nextWord, length + 1))
        
        return 0
