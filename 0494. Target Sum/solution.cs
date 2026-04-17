using System;

public class Solution {
    public int FindTargetSumWays(int[] nums, int target) {
        int total = 0;
        foreach (int num in nums) total += num;

        // invalid case
        if ((target + total) % 2 != 0 || Math.Abs(target) > total)
            return 0;

        int sum = (target + total) / 2;

        int[] dp = new int[sum + 1];
        dp[0] = 1;

        foreach (int num in nums) {
            for (int s = sum; s >= num; s--) {
                dp[s] += dp[s - num];
            }
        }

        return dp[sum];
    }
}
