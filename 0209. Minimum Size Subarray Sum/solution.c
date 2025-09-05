#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    long long currSum = 0;
    int minLen = INT_MAX;

    for (int right = 0; right < numsSize; right++) {
        currSum += nums[right];

        while (currSum >= target) {
            int len = right - left + 1;
            if (len < minLen) {
                minLen = len;
            }
            currSum -= nums[left++];
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}
