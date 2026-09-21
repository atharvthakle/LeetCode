class Solution {
    public long[] resultArray(int[] nums, int k) {
        long[] ans = new long[k];
        long[] dp = new long[k];

        for (int num : nums) {
            int x = num % k;
            long[] next = new long[k];

            // Subarray consisting only of nums[i]
            next[x]++;

            // Extend all previous subarrays ending at i - 1
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int nr = (int) ((long) r * x % k);
                    next[nr] += dp[r];
                }
            }

            dp = next;

            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
}
