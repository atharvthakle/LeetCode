#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

// Helper function for the linear version of the problem
int robLinear(int* nums, int start, int end) {
    int prev1 = 0, prev2 = 0; // prev1 = dp[i-1], prev2 = dp[i-2]
    for (int i = start; i <= end; i++) {
        int pick = nums[i] + prev2;
        int notPick = prev1;
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    // Case 1: exclude last house
    int case1 = robLinear(nums, 0, numsSize - 2);
    // Case 2: exclude first house
    int case2 = robLinear(nums, 1, numsSize - 1);
    return max(case1, case2);
}
