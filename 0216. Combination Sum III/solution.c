#include <stdio.h>
#include <stdlib.h>

void backtrack(int k, int n, int start, int *path, int pathLen, int ***res, int *returnSize, int **returnColumnSizes) {
    if (pathLen == k) {
        if (n == 0) {
            // Allocate memory for this combination
            int *comb = (int *)malloc(sizeof(int) * k);
            for (int i = 0; i < k; i++) comb[i] = path[i];

            // Append to results
            *res = (int **)realloc(*res, sizeof(int *) * (*returnSize + 1));
            (*res)[*returnSize] = comb;

            *returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
            (*returnColumnSizes)[*returnSize] = k;

            (*returnSize)++;
        }
        return;
    }

    for (int i = start; i <= 9; i++) {
        if (n - i < 0) break; // Prune if sum exceeds n
        path[pathLen] = i;
        backtrack(k, n - i, i + 1, path, pathLen + 1, res, returnSize, returnColumnSizes);
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    int **res = NULL;
    int path[9]; // Max k is 9

    backtrack(k, n, 1, path, 0, &res, returnSize, returnColumnSizes);

    return res;
}

// Example usage:
/*
int main() {
    int returnSize;
    int *returnColumnSizes;
    int **res = combinationSum3(3, 9, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d%s", res[i][j], j + 1 == returnColumnSizes[i] ? "" : ",");
        }
        printf("]\n");
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);
    return 0;
}
*/
