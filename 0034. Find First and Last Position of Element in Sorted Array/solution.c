#include <stdio.h>
#include <stdlib.h>

// Helper: binary search for first/last occurrence
int binarySearch(int* nums, int numsSize, int target, int findFirst) {
    int left = 0, right = numsSize - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;
            if (findFirst) {
                right = mid - 1; // keep searching left side
            } else {
                left = mid + 1;  // keep searching right side
            }
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

/**
 * Return an array of size 2, containing [firstPos, lastPos].
 * Caller must free the returned array.
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    if (numsSize == 0) return result;

    int first = binarySearch(nums, numsSize, target, 1);
    if (first == -1) return result; // target not found

    int last = binarySearch(nums, numsSize, target, 0);

    result[0] = first;
    result[1] = last;
    return result;
}
