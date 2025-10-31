#include <stdlib.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));  // worst case all duplicates
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;  // get the corresponding index

        if (nums[index] < 0) {
            // already visited once → duplicate found
            result[(*returnSize)++] = index + 1;
        } else {
            // mark as visited by negating
            nums[index] = -nums[index];
        }
    }

    return result;
}
