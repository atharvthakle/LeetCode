#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int* nums, int numsSize, int* curr, int currSize, int* used,
               int*** result, int* returnSize, int** returnColumnSizes) {
    if (currSize == numsSize) {
        // Allocate space for one permutation
        int* perm = (int*)malloc(numsSize * sizeof(int));
        memcpy(perm, curr, numsSize * sizeof(int));

        (*result)[*returnSize] = perm;
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {
            used[i] = 1;
            curr[currSize] = nums[i];
            backtrack(nums, numsSize, curr, currSize + 1, used,
                      result, returnSize, *returnColumnSizes ? returnColumnSizes : NULL);
            used[i] = 0;
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxPerms = 1;
    for (int i = 2; i <= numsSize; i++) maxPerms *= i;  // n!

    int** result = (int**)malloc(maxPerms * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxPerms * sizeof(int));

    int* curr = (int*)malloc(numsSize * sizeof(int));
    int* used = (int*)calloc(numsSize, sizeof(int));

    *returnSize = 0;
    backtrack(nums, numsSize, curr, 0, used, &result, returnSize, returnColumnSizes);

    free(curr);
    free(used);

    return result;
}
