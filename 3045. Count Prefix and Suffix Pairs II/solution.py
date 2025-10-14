class TrieNode:
    """
    A node in the Trie data structure.
    Uses __slots__ for memory optimization.
    """
    __slots__ = ["children", "count"]
  
    def __init__(self):
        # Dictionary to store child nodes, keyed by (prefix_char, suffix_char) tuples
        self.children = {}
        # Count of words that end at this node
        self.count = 0


class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        """
        Count the number of pairs (i, j) where i < j and words[i] is both 
        a prefix and suffix of words[j].
      
        The algorithm uses a Trie where each node represents a character pair
        (prefix_char, suffix_char). By traversing with paired characters from
        the start and end of each word simultaneously, we can efficiently check
        if previous words are both prefixes and suffixes.
      
        Args:
            words: List of strings to analyze
          
        Returns:
            Number of valid prefix-suffix pairs
        """
        result = 0
        root = TrieNode()
      
        # Process each word in order
        for word in words:
            current_node = root
          
            # Create character pairs: (first_char, last_char), (second_char, second_last_char), etc.
            # This allows checking prefix and suffix conditions simultaneously
            for char_pair in zip(word, reversed(word)):
                # Create new node if this character pair hasn't been seen at this position
                if char_pair not in current_node.children:
                    current_node.children[char_pair] = TrieNode()
              
                # Move to the child node corresponding to this character pair
                current_node = current_node.children[char_pair]
              
                # Add count of all previous words that match up to this position
                # These words are both prefixes and suffixes of the current word
                result += current_node.count
          
            # Mark that this word ends at the current node
            current_node.count += 1
      
        return result
