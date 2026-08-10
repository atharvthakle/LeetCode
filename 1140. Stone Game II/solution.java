class Solution {
    public int stoneGameII(int[] piles) {
        int n = piles.length;

        int[] suffix = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        int[][] dp = new int[n + 1][n + 1];

        for (int i = n - 1; i >= 0; i--) {
            for (int m = n; m >= 1; m--) {
                int maxTake = Math.min(2 * m, n - i);

                if (maxTake >= n - i) {
                    dp[i][m] = suffix[i];
                    continue;
                }

                int best = 0;

                for (int x = 1; x <= maxTake; x++) {
                    int opponent = dp[i + x][Math.max(m, x)];
                    best = Math.max(best, suffix[i] - opponent);
                }

                dp[i][m] = best;
            }
        }

        return dp[0][1];
    }
}
