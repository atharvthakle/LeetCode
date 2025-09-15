#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool **buildPalindromeTable(char *s, int n) {
    bool **dp = malloc(n * sizeof(bool *));
    for (int i = 0; i < n; i++) {
        dp[i] = calloc(n, sizeof(bool));
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
            }
        }
    }
    return dp;
}

// -------- Phase 1: Count total solutions --------
void countPaths(int start, int n, bool **dp, int *count) {
    if (start == n) {
        (*count)++;
        return;
    }
    for (int end = start; end < n; end++) {
        if (dp[start][end]) {
            countPaths(end + 1, n, dp, count);
        }
    }
}

// -------- Phase 2: Build results --------
void buildPaths(char *s, int start, int n, bool **dp,
                char ****res, int *resIndex, int **colSizes,
                int *path, int depth) {
    if (start == n) {
        int idx = (*resIndex)++;
        (*colSizes)[idx] = depth;
        (*res)[idx] = malloc(depth * sizeof(char *));
        for (int i = 0; i < depth; i++) {
            int st = path[2*i], en = path[2*i+1];
            int len = en - st + 1;
            char *substr = malloc(len + 1);
            memcpy(substr, s + st, len);
            substr[len] = '\0';
            (*res)[idx][i] = substr;
        }
        return;
    }
    for (int end = start; end < n; end++) {
        if (dp[start][end]) {
            path[2*depth] = start;
            path[2*depth+1] = end;
            buildPaths(s, end+1, n, dp, res, resIndex, colSizes, path, depth+1);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    bool **dp = buildPalindromeTable(s, n);

    // -------- First pass: count total solutions --------
    int total = 0;
    countPaths(0, n, dp, &total);

    // -------- Allocate once --------
    char ***res = malloc(total * sizeof(char **));
    *returnColumnSizes = malloc(total * sizeof(int));
    *returnSize = total;

    // -------- Second pass: build solutions --------
    int *path = malloc(2 * n * sizeof(int));
    int resIndex = 0;
    buildPaths(s, 0, n, dp, &res, &resIndex, returnColumnSizes, path, 0);

    // cleanup
    for (int i = 0; i < n; i++) free(dp[i]);
    free(dp);
    free(path);

    return res;
}
