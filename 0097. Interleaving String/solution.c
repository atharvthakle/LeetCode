#include <stdbool.h>
#include <string.h>

bool isInterleave(char* s1, char* s2, char* s3) {
    int m = strlen(s1), n = strlen(s2), l = strlen(s3);
    if (m + n != l) return false;

    bool dp[n + 1];
    memset(dp, false, sizeof(dp));

    dp[0] = true;

    // Initialize first row (using only s2)
    for (int j = 1; j <= n; j++) {
        dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
    }

    // Fill DP row by row using s1 and s2
    for (int i = 1; i <= m; i++) {
        dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
        for (int j = 1; j <= n; j++) {
            dp[j] = (dp[j] && (s1[i - 1] == s3[i + j - 1])) ||
                    (dp[j - 1] && (s2[j - 1] == s3[i + j - 1]));
        }
    }

    return dp[n];
}
