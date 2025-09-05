#include <string.h> // for memset

int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int maxLen = 0;

    // rolling DP arrays
    int dp[nums2Size + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = nums1Size - 1; i >= 0; i--) {
        int newDp[nums2Size + 1];
        memset(newDp, 0, sizeof(newDp));

        for (int j = nums2Size - 1; j >= 0; j--) {
            if (nums1[i] == nums2[j]) {
                newDp[j] = 1 + dp[j + 1];
                if (newDp[j] > maxLen) {
                    maxLen = newDp[j];
                }
            }
        }

        memcpy(dp, newDp, sizeof(dp));
    }

    return maxLen;
}
