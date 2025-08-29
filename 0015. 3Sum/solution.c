#include <stdlib.h>

// safe comparator (avoids potential overflow)
static int cmpfunc(const void* a, const void* b) {
    int va = *(const int*)a;
    int vb = *(const int*)b;
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (numsSize < 3) return NULL;

    // sort input
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    // dynamic storage for results
    int capacity = 16;
    int** result = (int**)malloc(capacity * sizeof(int*));
    int* colSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {
        // skip duplicates
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            long sum = (long)nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                // store triplet
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    colSizes = (int*)realloc(colSizes, capacity * sizeof(int));
                }
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                colSizes[*returnSize] = 3;
                (*returnSize)++;

                // skip duplicates for left and right
                int curLeft = nums[left], curRight = nums[right];
                while (left < right && nums[left] == curLeft) left++;
                while (left < right && nums[right] == curRight) right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    if (*returnSize == 0) {
        // no triplets found: free allocated arrays and return NULL
        free(result);
        free(colSizes);
        *returnColumnSizes = NULL;
        return NULL;
    }

    // shrink to actual size (optional)
    result = (int**)realloc(result, (*returnSize) * sizeof(int*));
    colSizes = (int*)realloc(colSizes, (*returnSize) * sizeof(int));
    *returnColumnSizes = colSizes;
    return result;
}
