#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int cmp(const void *a, const void *b) {
    long long x = *(int*)a;
    long long y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (numsSize < 4) return NULL;

    qsort(nums, numsSize, sizeof(int), cmp);

    int capacity = 1000; // initial guess capacity
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicate

            long long newTarget = (long long)target - nums[i] - nums[j];
            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                long long sum = (long long)nums[left] + nums[right];
                if (sum == newTarget) {
                    int* quad = (int*)malloc(4 * sizeof(int));
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];

                    if (*returnSize >= capacity) {
                        capacity *= 2;
                        result = (int**)realloc(result, capacity * sizeof(int*));
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                    }

                    result[*returnSize] = quad;
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    left++;
                    right--;

                    // skip duplicates
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < newTarget) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}
