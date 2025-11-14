#include <stdlib.h>
#include <string.h>

int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize,
                      int* returnSize, int** returnColumnSizes) {

    // Allocate & initialize difference matrix (n+1 x n+1)
    int** diff = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        diff[i] = (int*)calloc(n + 1, sizeof(int));
    }

    // Apply each query using 2D difference logic
    for (int q = 0; q < queriesSize; q++) {
        int r1 = queries[q][0];
        int c1 = queries[q][1];
        int r2 = queries[q][2];
        int c2 = queries[q][3];

        diff[r1][c1] += 1;
        if (c2 + 1 < n)
            diff[r1][c2 + 1] -= 1;
        if (r2 + 1 < n)
            diff[r2 + 1][c1] -= 1;
        if (r2 + 1 < n && c2 + 1 < n)
            diff[r2 + 1][c2 + 1] += 1;
    }

    // Allocate final matrix
    int** ans = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ans[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    // Build prefix sums → final matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = diff[i][j];
            if (i > 0) val += ans[i - 1][j];
            if (j > 0) val += ans[i][j - 1];
            if (i > 0 && j > 0) val -= ans[i - 1][j - 1];
            ans[i][j] = val;
        }
    }

    // Free diff matrix
    for (int i = 0; i <= n; i++) free(diff[i]);
    free(diff);

    *returnSize = n;
    return ans;
}
