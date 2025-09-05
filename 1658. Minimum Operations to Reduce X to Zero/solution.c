#include <stdio.h>

int minOperations(int* nums, int numsSize, int x) {
    long long total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }

    long long target = total - x;
    if (target < 0) return -1; // impossible

    int left = 0;
    long long currSum = 0;
    int maxLen = -1;

    for (int right = 0; right < numsSize; right++) {
        currSum += nums[right];

        // shrink window if sum exceeds target
        while (left <= right && currSum > target) {
            currSum -= nums[left++];
        }

        // found valid subarray
        if (currSum == target) {
            int len = right - left + 1;
            if (len > maxLen) maxLen = len;
        }
    }

    return (maxLen == -1) ? -1 : (numsSize - maxLen);
}
