public class Solution {
    public int MinDistance(string word1, string word2) {
        int n = word1.Length;
        int m = word2.Length;
        
        int[,] dp = new int[n + 1, m + 1];

        // Compute LCS length
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i, j] = dp[i - 1, j - 1] + 1;
                else
                    dp[i, j] = Math.Max(dp[i - 1, j], dp[i, j - 1]);
            }
        }

        int lcs = dp[n, m];
        return (n - lcs) + (m - lcs);
    }
}
