int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int prev2 = nums[0];                     // dp[i-2]
    int prev1 = (nums[0] > nums[1]) ? nums[0] : nums[1]; // dp[i-1]

    for (int i = 2; i < numsSize; i++) {
        int curr = (prev1 > prev2 + nums[i]) ? prev1 : (prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1
}
