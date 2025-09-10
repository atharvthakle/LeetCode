int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    if (triangleSize == 0) return 0;

    // Allocate a 1D array to store minimum path sums of the current row
    int dp[triangleSize];
    
    // Initialize dp with the last row of the triangle
    for (int i = 0; i < triangleColSize[triangleSize - 1]; ++i) {
        dp[i] = triangle[triangleSize - 1][i];
    }
    
    // Bottom-up calculation
    for (int i = triangleSize - 2; i >= 0; --i) {
        for (int j = 0; j < triangleColSize[i]; ++j) {
            if (dp[j] < dp[j + 1])
                dp[j] = triangle[i][j] + dp[j];
            else
                dp[j] = triangle[i][j] + dp[j + 1];
        }
    }
    
    return dp[0];
}
