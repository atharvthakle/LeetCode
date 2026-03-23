public class Solution {
    public int MaxProductPath(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        long[,] maxDp = new long[m, n];
        long[,] minDp = new long[m, n];

        maxDp[0, 0] = grid[0][0];
        minDp[0, 0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) continue;

                long maxVal = long.MinValue;
                long minVal = long.MaxValue;

                if (i > 0) {
                    long a = maxDp[i - 1, j] * grid[i][j];
                    long b = minDp[i - 1, j] * grid[i][j];
                    maxVal = Math.Max(maxVal, Math.Max(a, b));
                    minVal = Math.Min(minVal, Math.Min(a, b));
                }

                if (j > 0) {
                    long a = maxDp[i, j - 1] * grid[i][j];
                    long b = minDp[i, j - 1] * grid[i][j];
                    maxVal = Math.Max(maxVal, Math.Max(a, b));
                    minVal = Math.Min(minVal, Math.Min(a, b));
                }

                maxDp[i, j] = maxVal;
                minDp[i, j] = minVal;
            }
        }

        long result = maxDp[m - 1, n - 1];
        if (result < 0) return -1;

        return (int)(result % 1_000_000_007);
    }
}
