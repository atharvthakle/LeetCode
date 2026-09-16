class Solution {
    public int numberOfSets(int n, int k) {
        final long MOD = 1_000_000_007L;
        
        long[][] dp = new long[k + 1][n];
        dp[0][0] = 1;

        for (int j = 1; j < n; j++) {
            dp[0][j] = 1;
        }

        for (int seg = 1; seg <= k; seg++) {
            long sum = 0;

            for (int j = 1; j < n; j++) {
                sum = (sum + dp[seg - 1][j - 1]) % MOD;
                dp[seg][j] = (dp[seg][j - 1] + sum) % MOD;
            }
        }

        return (int) dp[k][n - 1];
    }
}
