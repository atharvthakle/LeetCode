public class Solution {
    public int CombinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];
        dp[0] = 1;

        for (int t = 1; t <= target; t++) {
            foreach (int num in nums) {
                if (t >= num) {
                    dp[t] += dp[t - num];
                }
            }
        }

        return dp[target];
    }
}
