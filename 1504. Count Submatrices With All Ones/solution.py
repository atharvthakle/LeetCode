from typing import List

class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        heights = [0] * n
        total = 0
        
        for i in range(m):
            # Build histogram for row i
            for j in range(n):
                if mat[i][j] == 1:
                    heights[j] += 1
                else:
                    heights[j] = 0
            
            # Count submatrices using histogram
            stack = []
            count = [0] * n
            for j in range(n):
                # maintain increasing stack
                while stack and heights[stack[-1]] >= heights[j]:
                    stack.pop()
                
                if stack:
                    prev = stack[-1]
                    count[j] = count[prev] + heights[j] * (j - prev)
                else:
                    count[j] = heights[j] * (j + 1)
                
                stack.append(j)
                total += count[j]
        
        return total
