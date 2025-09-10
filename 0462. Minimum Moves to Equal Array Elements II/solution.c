#include <stdlib.h>

// Comparator for qsort
int cmp(const void* a, const void* b) {
    long x = *(int*)a;
    long y = *(int*)b;
    return (x > y) - (x < y); // same as: if (x>y) return 1; else if (x<y) return -1; else 0
}

int minMoves2(int* nums, int numsSize) {
    // Sort nums
    qsort(nums, numsSize, sizeof(int), cmp);
    
    // Median element
    int median = nums[numsSize / 2];
    
    long moves = 0;
    for (int i = 0; i < numsSize; i++) {
        moves += abs(nums[i] - median);
    }
    
    return (int)moves;
}
