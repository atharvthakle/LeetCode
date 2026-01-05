public class Solution {
    public int GetMoneyAmount(int n) {
        int[,] dp = new int[n + 2, n + 2];

        // length of interval
        for (int len = 2; len <= n; len++) {
            for (int left = 1; left + len - 1 <= n; left++) {
                int right = left + len - 1;
                dp[left, right] = int.MaxValue;

                for (int guess = left; guess <= right; guess++) {
                    int cost = guess +
                               Math.Max(
                                   guess > left ? dp[left, guess - 1] : 0,
                                   guess < right ? dp[guess + 1, right] : 0
                               );

                    dp[left, right] = Math.Min(dp[left, right], cost);
                }
            }
        }

        return dp[1, n];
    }
}
