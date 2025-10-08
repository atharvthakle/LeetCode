#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int maximumGap(int* nums, int numsSize){
    if(numsSize < 2) return 0;

    int i;
    int minVal = INT_MAX, maxVal = INT_MIN;
    for(i = 0; i < numsSize; i++){
        if(nums[i] < minVal) minVal = nums[i];
        if(nums[i] > maxVal) maxVal = nums[i];
    }

    if(minVal == maxVal) return 0;

    int n = numsSize;
    int bucketSize = (int)ceil((double)(maxVal - minVal)/(n-1));

    int *bucketMin = (int*)malloc(n * sizeof(int));
    int *bucketMax = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++){
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Fill the buckets
    for(i = 0; i < n; i++){
        int idx = (nums[i] - minVal) / bucketSize;
        if(nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if(nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
    }

    int maxGap = 0;
    int prevMax = minVal;
    for(i = 0; i < n; i++){
        if(bucketMin[i] == INT_MAX) continue; // empty bucket
        int gap = bucketMin[i] - prevMax;
        if(gap > maxGap) maxGap = gap;
        prevMax = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    return maxGap;
}
