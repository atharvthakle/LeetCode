from collections import defaultdict, deque
from typing import List

class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return []
        
        # BFS to build predecessors map and distance map
        preds = defaultdict(list)  # word -> list of predecessors
        distance = {beginWord: 0}
        queue = deque([beginWord])
        L = len(beginWord)
        
        while queue:
            word = queue.popleft()
            for i in range(L):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    nxt = word[:i] + c + word[i+1:]
                    if nxt in wordSet:
                        if nxt not in distance:  # first time visiting
                            distance[nxt] = distance[word] + 1
                            queue.append(nxt)
                            preds[nxt].append(word)
                        elif distance[nxt] == distance[word] + 1:  # another shortest path
                            preds[nxt].append(word)
        
        # DFS to reconstruct paths from endWord to beginWord
        res = []
        def dfs(word, path):
            if word == beginWord:
                res.append(path[::-1])
                return
            for pre in preds[word]:
                dfs(pre, path + [pre])
        
        if endWord in distance:
            dfs(endWord, [endWord])
        
        return res
