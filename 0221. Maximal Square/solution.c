#include <stdlib.h>
#include <string.h>

int minimal(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) 
        return 0;
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int maxSide = 0;

    // Create DP array (use int to store side lengths)
    int** dp = (int**)malloc((rows + 1) * sizeof(int*));
    for (int i = 0; i <= rows; i++) {
        dp[i] = (int*)calloc(cols + 1, sizeof(int));
    }

    // Fill DP table
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = 1 + minimal(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
                if (dp[i][j] > maxSide)
                    maxSide = dp[i][j];
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i <= rows; i++)
        free(dp[i]);
    free(dp);

    return maxSide * maxSide; // Return area
}
