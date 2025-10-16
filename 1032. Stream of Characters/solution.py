from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class StreamChecker:

    def __init__(self, words: List[str]):
        self.trie = TrieNode()
        self.stream = []
        self.max_len = 0

        # Insert reversed words into trie
        for word in words:
            self.max_len = max(self.max_len, len(word))
            node = self.trie
            for ch in reversed(word):
                if ch not in node.children:
                    node.children[ch] = TrieNode()
                node = node.children[ch]
            node.is_end = True

    def query(self, letter: str) -> bool:
        self.stream.append(letter)

        # Only need to check up to max word length
        node = self.trie
        for ch in reversed(self.stream[-self.max_len:]):
            if ch not in node.children:
                return False
            node = node.children[ch]
            if node.is_end:
                return True
        return False
