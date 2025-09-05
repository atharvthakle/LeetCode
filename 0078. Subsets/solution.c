#include <stdio.h>
#include <stdlib.h>

void backtrack(int* nums, int numsSize, int start, int* subset, int subsetSize,
               int** res, int* returnSize, int** returnColumnSizes) {
    // Store current subset
    res[*returnSize] = (int*)malloc(subsetSize * sizeof(int));
    for (int i = 0; i < subsetSize; i++) {
        res[*returnSize][i] = subset[i];
    }
    (*returnColumnSizes)[*returnSize] = subsetSize;
    (*returnSize)++;

    // Explore further elements to add
    for (int i = start; i < numsSize; i++) {
        subset[subsetSize] = nums[i];
        backtrack(nums, numsSize, i + 1, subset, subsetSize + 1, res, returnSize, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1 << numsSize; // 2^n subsets
    int** res = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    *returnSize = 0;

    int* subset = (int*)malloc(numsSize * sizeof(int));
    backtrack(nums, numsSize, 0, subset, 0, res, returnSize, returnColumnSizes);
    free(subset);
    return res;
}
