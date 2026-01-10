public class Solution {
    public int MinimumDeleteSum(string s1, string s2) {
        int n = s1.Length, m = s2.Length;
        int[,] dp = new int[n + 1, m + 1];

        // Base case: delete remaining characters
        for (int i = n - 1; i >= 0; i--)
            dp[i, m] = dp[i + 1, m] + s1[i];

        for (int j = m - 1; j >= 0; j--)
            dp[n, j] = dp[n, j + 1] + s2[j];

        // Fill DP table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i, j] = dp[i + 1, j + 1];
                } else {
                    int deleteS1 = s1[i] + dp[i + 1, j];
                    int deleteS2 = s2[j] + dp[i, j + 1];
                    dp[i, j] = Math.Min(deleteS1, deleteS2);
                }
            }
        }

        return dp[0, 0];
    }
}
