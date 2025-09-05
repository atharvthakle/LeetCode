#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int min3(int a, int b, int c) {
    return min(min(a, b), c);
}

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min3(dp[i - 1][j],    // delete
                                    dp[i][j - 1],    // insert
                                    dp[i - 1][j - 1] // replace
                                   );
            }
        }
    }

    int result = dp[m][n];

    // Free memory
    for (int i = 0; i <= m; i++) free(dp[i]);
    free(dp);

    return result;
}
