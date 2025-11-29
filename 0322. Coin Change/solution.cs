public class Solution {
    public int CoinChange(int[] coins, int amount) {
        int max = amount + 1;
        int[] dp = new int[amount + 1];

        // Fill dp with a large sentinel value
        for (int i = 1; i <= amount; i++)
            dp[i] = max;

        // Base case
        dp[0] = 0;

        // Compute the fewest coins for every sub-amount
        for (int i = 1; i <= amount; i++) {
            foreach (int coin in coins) {
                if (coin <= i) {
                    dp[i] = Math.Min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
}
