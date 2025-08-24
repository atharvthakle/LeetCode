int longestSubarray(int* nums, int numsSize) {
    int left = 0, right = 0;
    int zeroCount = 0;
    int maxLen = 0;

    for (right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            zeroCount++;
        }

        while (zeroCount > 1) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }

        // window size minus 1 (since we must delete one element)
        maxLen = (right - left) > maxLen ? (right - left) : maxLen;
    }

    return maxLen;
}
