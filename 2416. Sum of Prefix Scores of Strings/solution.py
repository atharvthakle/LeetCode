from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.count = 0  # how many words pass through this node

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        root = TrieNode()

        # Build trie and count prefix frequencies
        for word in words:
            node = root
            for c in word:
                if c not in node.children:
                    node.children[c] = TrieNode()
                node = node.children[c]
                node.count += 1

        # For each word, calculate sum of prefix scores
        result = []
        for word in words:
            node = root
            total = 0
            for c in word:
                node = node.children[c]
                total += node.count
            result.append(total)

        return result
