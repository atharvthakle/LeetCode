using System;

public class Solution {
    public int MaximumAmount(int[][] coins) {
        int m = coins.Length, n = coins[0].Length;
        
        int[,,] dp = new int[m, n, 3];

        // Initialize with very small values
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 3; k++)
                    dp[i, j, k] = int.MinValue;

        // Start position
        dp[0, 0, 0] = coins[0][0];

        if (coins[0][0] < 0) {
            dp[0, 0, 1] = 0; // neutralize
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    if (dp[i, j, k] == int.MinValue) continue;

                    // move right
                    if (j + 1 < n) {
                        int val = coins[i][j+1];

                        // take normally
                        dp[i, j+1, k] = Math.Max(dp[i, j+1, k], dp[i, j, k] + val);

                        // neutralize if negative
                        if (val < 0 && k < 2) {
                            dp[i, j+1, k+1] = Math.Max(dp[i, j+1, k+1], dp[i, j, k]);
                        }
                    }

                    // move down
                    if (i + 1 < m) {
                        int val = coins[i+1][j];

                        // take normally
                        dp[i+1, j, k] = Math.Max(dp[i+1, j, k], dp[i, j, k] + val);

                        // neutralize if negative
                        if (val < 0 && k < 2) {
                            dp[i+1, j, k+1] = Math.Max(dp[i+1, j, k+1], dp[i, j, k]);
                        }
                    }
                }
            }
        }

        int res = int.MinValue;
        for (int k = 0; k < 3; k++) {
            res = Math.Max(res, dp[m-1, n-1, k]);
        }

        return res;
    }
}
