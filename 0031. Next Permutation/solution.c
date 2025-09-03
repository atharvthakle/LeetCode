#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* nums, int left, int right) {
    while (left < right) {
        swap(&nums[left], &nums[right]);
        left++;
        right--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    if (numsSize <= 1) return;

    int i = numsSize - 2;

    // Step 1: Find pivot
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Step 2: Find successor
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(&nums[i], &nums[j]);
    }

    // Step 3: Reverse suffix
    reverse(nums, i + 1, numsSize - 1);
}
