#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (x > y) - (x < y); // safer comparison
}

int maxDistinctElements(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    
    long current = -10000000000L; // sufficiently small
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        long left = (long)nums[i] - k;
        long right = (long)nums[i] + k;
        
        if (current < left) current = left; // move current into range start
        
        if (current <= right) { // current fits in the range
            count++;
            current++; // move to next possible distinct number
        }
    }
    
    return count;
}
