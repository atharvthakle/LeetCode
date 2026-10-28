class Solution {
    public int minCost(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] dp = new int[m][n][1024];

        for (int[][] row : dp) {
            for (int[] cell : row) {
                java.util.Arrays.fill(cell, 0);
            }
        }

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i - 1][j][x] != 0) {
                            dp[i][j][x ^ grid[i][j]] = 1;
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i][j - 1][x] != 0) {
                            dp[i][j][x ^ grid[i][j]] = 1;
                        }
                    }
                }
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1][x] != 0) {
                return x;
            }
        }

        return 0;
    }
}
