from functools import lru_cache
from typing import List

class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        
        # Quick check: total length must be even
        if (m + n - 1) % 2 == 1:
            return False

        @lru_cache(None)
        def dfs(i: int, j: int, balance: int) -> bool:
            # If balance is invalid
            if balance < 0:
                return False
            
            # Add or subtract balance depending on char
            if grid[i][j] == "(":
                balance += 1
            else:
                balance -= 1
            
            # If invalid
            if balance < 0:
                return False
            
            # Reached end
            if i == m - 1 and j == n - 1:
                return balance == 0
            
            # Explore right and down
            if i + 1 < m and dfs(i + 1, j, balance):
                return True
            if j + 1 < n and dfs(i, j + 1, balance):
                return True
            
            return False

        return dfs(0, 0, 0)
