from functools import lru_cache

class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        @lru_cache(None)
        def dfs(a: str, b: str) -> bool:
            if a == b:
                return True
            if sorted(a) != sorted(b):  # quick pruning: different character counts
                return False
            
            n = len(a)
            for i in range(1, n):
                # Check without swap
                if dfs(a[:i], b[:i]) and dfs(a[i:], b[i:]):
                    return True
                # Check with swap
                if dfs(a[:i], b[-i:]) and dfs(a[i:], b[:-i]):
                    return True
            return False
        
        return dfs(s1, s2)
