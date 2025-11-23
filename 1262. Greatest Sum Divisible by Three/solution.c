#include <limits.h>

int maxSumDivThree(int* nums, int numsSize) {
    int dp[3] = {0, INT_MIN, INT_MIN};

    for (int i = 0; i < numsSize; ++i) {
        int temp[3];
        for (int r = 0; r < 3; ++r) temp[r] = dp[r];

        for (int r = 0; r < 3; ++r) {
            if (dp[r] == INT_MIN) continue; // skip invalid states
            int new_sum = dp[r] + nums[i];
            int rem = new_sum % 3;
            if (rem < 0) rem += 3; // make remainder non-negative
            if (new_sum > temp[rem]) temp[rem] = new_sum;
        }

        for (int r = 0; r < 3; ++r) dp[r] = temp[r];
    }

    return dp[0];
}
