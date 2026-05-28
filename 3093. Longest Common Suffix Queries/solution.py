from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.best_idx = -1
        self.best_len = float('inf')


class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:

        root = TrieNode()

        # insert reversed container words into trie
        for idx, word in enumerate(wordsContainer):
            node = root
            wlen = len(word)

            # update best candidate at root
            if wlen < node.best_len:
                node.best_len = wlen
                node.best_idx = idx

            for ch in reversed(word):
                if ch not in node.children:
                    node.children[ch] = TrieNode()

                node = node.children[ch]

                # keep shortest length / earliest index
                if wlen < node.best_len:
                    node.best_len = wlen
                    node.best_idx = idx

        ans = []

        # query longest common suffix
        for word in wordsQuery:
            node = root

            for ch in reversed(word):
                if ch not in node.children:
                    break
                node = node.children[ch]

            ans.append(node.best_idx)

        return ans
