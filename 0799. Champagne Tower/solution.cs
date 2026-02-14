public class Solution {
    public double ChampagneTower(int poured, int query_row, int query_glass) {
        double[][] dp = new double[101][];
        for (int i = 0; i < 101; i++) {
            dp[i] = new double[101];
        }

        dp[0][0] = poured;

        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] > 1.0) {
                    double excess = (dp[i][j] - 1.0) / 2.0;
                    dp[i+1][j] += excess;
                    dp[i+1][j+1] += excess;
                }
            }
        }

        return Math.Min(1.0, dp[query_row][query_glass]);
    }
}
