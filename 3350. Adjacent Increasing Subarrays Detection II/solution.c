#include <stdio.h>
#include <stdlib.h>

int maxIncreasingSubarrays(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int *left = (int*)malloc(sizeof(int) * numsSize);
    int *right = (int*)malloc(sizeof(int) * numsSize);

    // left[i] = length of increasing sequence ending at i
    left[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 1;
    }

    // right[i] = length of increasing sequence starting at i
    right[numsSize - 1] = 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1])
            right[i] = right[i + 1] + 1;
        else
            right[i] = 1;
    }

    int maxK = 0;

    // Check adjacent subarrays: left[i] and right[i+1]
    for (int i = 0; i < numsSize - 1; i++) {
        int k = left[i] < right[i + 1] ? left[i] : right[i + 1];
        if (k > maxK)
            maxK = k;
    }

    free(left);
    free(right);
    return maxK;
}

// Example usage
/*
int main() {
    int nums1[] = {2,5,7,8,9,2,3,4,3,1};
    int numsSize1 = sizeof(nums1)/sizeof(nums1[0]);
    printf("%d\n", maxIncreasingSubarrays(nums1, numsSize1)); // Output: 3

    int nums2[] = {1,2,3,4,4,4,4,5,6,7};
    int numsSize2 = sizeof(nums2)/sizeof(nums2[0]);
    printf("%d\n", maxIncreasingSubarrays(nums2, numsSize2)); // Output: 2
    return 0;
}
*/
