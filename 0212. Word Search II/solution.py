from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None  # store complete word at end node

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # Build Trie
        root = TrieNode()
        for word in words:
            node = root
            for ch in word:
                if ch not in node.children:
                    node.children[ch] = TrieNode()
                node = node.children[ch]
            node.word = word  # mark the end of a word
        
        m, n = len(board), len(board[0])
        res = []

        def dfs(i, j, node):
            if node.word:  # found a word
                res.append(node.word)
                node.word = None  # avoid duplicates
            
            if i < 0 or i >= m or j < 0 or j >= n or board[i][j] not in node.children:
                return
            
            ch = board[i][j]
            board[i][j] = '#'  # mark visited
            for x, y in [(i+1,j),(i-1,j),(i,j+1),(i,j-1)]:
                dfs(x, y, node.children[ch])
            board[i][j] = ch  # unmark
        
        for i in range(m):
            for j in range(n):
                dfs(i, j, root)
        
        return res
