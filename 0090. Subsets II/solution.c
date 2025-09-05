#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int start, int* subset, int subsetSize,
               int** res, int* returnSize, int** returnColumnSizes) {
    // Store the current subset
    res[*returnSize] = (int*)malloc(subsetSize * sizeof(int));
    for (int i = 0; i < subsetSize; i++)
        res[*returnSize][i] = subset[i];
    (*returnColumnSizes)[*returnSize] = subsetSize;
    (*returnSize)++;

    // Explore further elements
    for (int i = start; i < numsSize; i++) {
        // Skip duplicates
        if (i > start && nums[i] == nums[i - 1])
            continue;
        subset[subsetSize] = nums[i];
        backtrack(nums, numsSize, i + 1, subset, subsetSize + 1, res, returnSize, returnColumnSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1 << numsSize; // maximum possible subsets
    int** res = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    int* subset = (int*)malloc(numsSize * sizeof(int));
    backtrack(nums, numsSize, 0, subset, 0, res, returnSize, returnColumnSizes);
    free(subset);

    return res;
}
