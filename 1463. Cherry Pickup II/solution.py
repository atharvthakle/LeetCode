from typing import List

class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        
        # dp[c1][c2] = max cherries at current row
        dp = [[-1] * cols for _ in range(cols)]
        dp[0][cols - 1] = grid[0][0] + (grid[0][cols - 1] if cols - 1 != 0 else 0)
        
        for r in range(1, rows):
            new_dp = [[-1] * cols for _ in range(cols)]
            
            for c1 in range(cols):
                for c2 in range(cols):
                    if dp[c1][c2] == -1:
                        continue
                    
                    # try all moves for both robots
                    for d1 in (-1, 0, 1):
                        for d2 in (-1, 0, 1):
                            nc1, nc2 = c1 + d1, c2 + d2
                            
                            if 0 <= nc1 < cols and 0 <= nc2 < cols:
                                cherries = dp[c1][c2]
                                
                                # collect cherries at new row
                                if nc1 == nc2:
                                    cherries += grid[r][nc1]
                                else:
                                    cherries += grid[r][nc1] + grid[r][nc2]
                                
                                new_dp[nc1][nc2] = max(new_dp[nc1][nc2], cherries)
            
            dp = new_dp
        
        # answer is the best configuration on the last row
        return max(max(row) for row in dp)
