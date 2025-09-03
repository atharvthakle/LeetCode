#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int* curr, int currSize, int* used,
               int*** result, int* returnSize, int** returnColumnSizes) {
    if (currSize == numsSize) {
        int* perm = (int*)malloc(numsSize * sizeof(int));
        memcpy(perm, curr, numsSize * sizeof(int));

        (*result)[*returnSize] = perm;
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;

        // Skip duplicates
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

        used[i] = 1;
        curr[currSize] = nums[i];
        backtrack(nums, numsSize, curr, currSize + 1, used,
                  result, returnSize, returnColumnSizes);
        used[i] = 0;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Maximum possible permutations is n! (upper bound)
    int maxPerms = 1;
    for (int i = 2; i <= numsSize; i++) maxPerms *= i;

    int** result = (int**)malloc(maxPerms * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxPerms * sizeof(int));

    int* curr = (int*)malloc(numsSize * sizeof(int));
    int* used = (int*)calloc(numsSize, sizeof(int));

    *returnSize = 0;

    // Sort nums to handle duplicates
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    backtrack(nums, numsSize, curr, 0, used, &result, returnSize, returnColumnSizes);

    free(curr);
    free(used);

    return result;
}
