public class Solution {
    public bool CanPartition(int[] nums) {
        int sum = 0;
        foreach (int num in nums) sum += num;

        // If total sum is odd, cannot split equally
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        bool[] dp = new bool[target + 1];
        dp[0] = true;

        foreach (int num in nums) {
            // traverse backwards to prevent reuse
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
}
