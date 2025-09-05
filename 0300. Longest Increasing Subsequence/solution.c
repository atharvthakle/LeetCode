#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int* sub = (int*)malloc(numsSize * sizeof(int));
    int length = 0;

    for (int i = 0; i < numsSize; i++) {
        int left = 0, right = length;

        // Binary search for the first element >= nums[i]
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sub[mid] < nums[i])
                left = mid + 1;
            else
                right = mid;
        }

        // If left == length, append; else replace
        sub[left] = nums[i];
        if (left == length) length++;
    }

    free(sub);
    return length;
}
