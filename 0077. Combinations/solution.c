#include <stdio.h>
#include <stdlib.h>

void backtrack(int n, int k, int start, int* comb, int combSize, 
               int*** res, int* returnSize, int** returnColumnSizes) {
    if (combSize == k) {
        (*res)[*returnSize] = (int*)malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) {
            (*res)[*returnSize][i] = comb[i];
        }
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;
    }

    for (int i = start; i <= n; i++) {
        comb[combSize] = i;
        backtrack(n, k, i + 1, comb, combSize + 1, res, returnSize, returnColumnSizes);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int total = 1;
    // Calculate n choose k (upper bound for allocations)
    for (int i = 0; i < k; i++) {
        total *= (n - i);
        total /= (i + 1);
    }

    int** res = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    *returnSize = 0;

    int* comb = (int*)malloc(k * sizeof(int));
    backtrack(n, k, 1, comb, 0, &res, returnSize, returnColumnSizes);
    free(comb);

    return res;
}
