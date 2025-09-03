from collections import Counter, defaultdict

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""
        
        need = Counter(t)        # count of chars we need
        window = defaultdict(int)
        
        have, need_count = 0, len(need)
        res, res_len = [-1, -1], float("inf")
        left = 0
        
        # expand window with right pointer
        for right in range(len(s)):
            c = s[right]
            window[c] += 1
            
            if c in need and window[c] == need[c]:
                have += 1
            
            # when all requirements met, try to shrink from left
            while have == need_count:
                # update result
                if (right - left + 1) < res_len:
                    res = [left, right]
                    res_len = right - left + 1
                
                # shrink from left
                window[s[left]] -= 1
                if s[left] in need and window[s[left]] < need[s[left]]:
                    have -= 1
                left += 1
        
        l, r = res
        return s[l:r+1] if res_len != float("inf") else ""
