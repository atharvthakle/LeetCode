int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;

    int dp[m][n];

    // Fill dp table
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];  // start
            } else {
                int fromTop = (i > 0) ? dp[i-1][j] : 1e9;
                int fromLeft = (j > 0) ? dp[i][j-1] : 1e9;
                dp[i][j] = grid[i][j] + (fromTop < fromLeft ? fromTop : fromLeft);
            }
        }
    }

    return dp[m-1][n-1];
}
