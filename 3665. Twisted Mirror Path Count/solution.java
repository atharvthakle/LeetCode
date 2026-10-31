class Solution {
    public int uniquePaths(int[][] grid) {
        int MOD = 1_000_000_007;
        int m = grid.length;
        int n = grid[0].length;

        long[][] right = new long[m][n];
        long[][] down = new long[m][n];

        right[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long r = right[i][j];
                long d = down[i][j];

                if (i == m - 1 && j == n - 1) {
                    continue;
                }

                if (grid[i][j] == 0) {
                    long ways = (r + d) % MOD;

                    if (j + 1 < n) {
                        right[i][j + 1] = (right[i][j + 1] + ways) % MOD;
                    }

                    if (i + 1 < m) {
                        down[i + 1][j] = (down[i + 1][j] + ways) % MOD;
                    }
                } else {
                    if (r > 0 && i + 1 < m) {
                        down[i + 1][j] = (down[i + 1][j] + r) % MOD;
                    }

                    if (d > 0 && j + 1 < n) {
                        right[i][j + 1] = (right[i][j + 1] + d) % MOD;
                    }
                }
            }
        }

        return (int) ((right[m - 1][n - 1] + down[m - 1][n - 1]) % MOD);
    }
}
