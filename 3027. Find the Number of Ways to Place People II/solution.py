class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        n = len(points)
        ans = 0
        
        # Extract x and y coordinates separately
        xs = sorted(set(p[0] for p in points))
        ys = sorted(set(p[1] for p in points))
        
        # Coordinate compression
        x_map = {x:i for i,x in enumerate(xs)}
        y_map = {y:i for i,y in enumerate(ys)}
        
        # 2D grid for prefix sums
        m, k = len(xs), len(ys)
        grid = [[0]*(k+1) for _ in range(m+1)]
        
        for x, y in points:
            grid[x_map[x]+1][y_map[y]+1] += 1
        
        # 2D prefix sum
        for i in range(1, m+1):
            for j in range(1, k+1):
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]
        
        # Function to query number of points inside rectangle
        def query(x1, y1, x2, y2):
            return grid[x2+1][y2+1] - grid[x1][y2+1] - grid[x2+1][y1] + grid[x1][y1]
        
        # Check each pair (Alice, Bob)
        for i in range(n):
            ax, ay = points[i]
            xi = x_map[ax]
            yi = y_map[ay]
            for j in range(n):
                if i == j:
                    continue
                bx, by = points[j]
                xj = x_map[bx]
                yj = y_map[by]
                
                # Alice = upper-left, Bob = lower-right
                if xi <= xj and yi >= yj:
                    # Count points in rectangle
                    count = query(xi, yj, xj, yi)
                    # Exclude Alice and Bob
                    if count == 2:
                        ans += 1
        return ans
