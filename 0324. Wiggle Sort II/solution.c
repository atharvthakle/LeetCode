#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void wiggleSort(int* nums, int numsSize) {
    if (numsSize <= 1) return;

    // Step 1: Sort a copy of nums
    int* sorted = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        sorted[i] = nums[i];
    }
    qsort(sorted, numsSize, sizeof(int), cmp);

    // Step 2: Fill nums by placing smaller half at even indices,
    // and larger half at odd indices (in reverse order to avoid conflicts)
    int mid = (numsSize + 1) / 2;  // Middle of array
    int j = mid - 1;               // End of smaller half
    int k = numsSize - 1;          // End of larger half

    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            nums[i] = sorted[j--]; // Place from smaller half
        } else {
            nums[i] = sorted[k--]; // Place from larger half
        }
    }

    free(sorted);
}
