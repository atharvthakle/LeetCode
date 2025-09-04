int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = *obstacleGridColSize;

    // If start or end is blocked, no path
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
        return 0;
    }

    int dp[m][n];
    
    // Initialize
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0; // blocked
            } else if (i == 0 && j == 0) {
                dp[i][j] = 1; // start
            } else {
                int fromTop = (i > 0) ? dp[i-1][j] : 0;
                int fromLeft = (j > 0) ? dp[i][j-1] : 0;
                dp[i][j] = fromTop + fromLeft;
            }
        }
    }

    return dp[m-1][n-1];
}
