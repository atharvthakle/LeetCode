from collections import Counter
from typing import List

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []
        
        word_len = len(words[0])
        total_len = word_len * len(words)
        word_count = Counter(words)
        n = len(s)
        
        res = []
        
        # We need to check windows starting at each offset within word_len
        for i in range(word_len):
            left = i
            right = i
            cur_count = Counter()
            
            while right + word_len <= n:
                word = s[right:right + word_len]
                right += word_len
                
                if word in word_count:
                    cur_count[word] += 1
                    
                    # If a word appears more than needed, shrink from left
                    while cur_count[word] > word_count[word]:
                        cur_count[s[left:left + word_len]] -= 1
                        left += word_len
                    
                    # If window size matches total_len, valid start
                    if right - left == total_len:
                        res.append(left)
                else:
                    # Reset if invalid word
                    cur_count.clear()
                    left = right
        
        return res
