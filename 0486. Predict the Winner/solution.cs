public class Solution {
    public bool PredictTheWinner(int[] nums) {
        int n = nums.Length;
        int[,] dp = new int[n, n];

        // base case
        for (int i = 0; i < n; i++) {
            dp[i, i] = nums[i];
        }

        // fill DP
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                int pickLeft = nums[i] - dp[i + 1, j];
                int pickRight = nums[j] - dp[i, j - 1];

                dp[i, j] = Math.Max(pickLeft, pickRight);
            }
        }

        return dp[0, n - 1] >= 0;
    }
}
