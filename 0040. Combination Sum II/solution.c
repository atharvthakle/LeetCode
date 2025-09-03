#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

#define MAX_RESULTS 10000
#define MAX_COMB 100

int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);

    int** results = (int**)malloc(MAX_RESULTS * sizeof(int*));
    *returnColumnSizes = (int*)malloc(MAX_RESULTS * sizeof(int));
    *returnSize = 0;

    int* comb = (int*)malloc(MAX_COMB * sizeof(int));

    // Backtracking function
    void backtrack(int start, int remain, int depth) {
        if (remain == 0) {
            // Found valid combination
            results[*returnSize] = (int*)malloc(depth * sizeof(int));
            for (int j = 0; j < depth; j++) {
                results[*returnSize][j] = comb[j];
            }
            (*returnColumnSizes)[*returnSize] = depth;
            (*returnSize)++;
            return;
        }

        for (int i = start; i < candidatesSize; i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue; // skip duplicates
            if (candidates[i] > remain) break; // prune

            comb[depth] = candidates[i];
            backtrack(i + 1, remain - candidates[i], depth + 1);
        }
    }

    backtrack(0, target, 0);

    free(comb);
    return results;
}
