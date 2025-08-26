int longestOnes(int* nums, int numsSize, int k) {
    int left = 0, right = 0;
    int zeroCount = 0;
    int maxLen = 0;

    for (right = 0; right < numsSize; right++) {
        if (nums[right] == 0)
            zeroCount++;

        // shrink window until zeroCount <= k
        while (zeroCount > k) {
            if (nums[left] == 0)
                zeroCount--;
            left++;
        }

        // update max length
        int currLen = right - left + 1;
        if (currLen > maxLen)
            maxLen = currLen;
    }

    return maxLen;
}
