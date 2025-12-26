public class Solution {
    public long GridGame(int[][] grid) {
        int n = grid[0].Length;

        // Prefix sums for bottom row
        long[] bottomPrefix = new long[n + 1];
        for (int i = 0; i < n; i++) {
            bottomPrefix[i + 1] = bottomPrefix[i] + grid[1][i];
        }

        // Total sum of top row
        long topSum = 0;
        for (int i = 0; i < n; i++) {
            topSum += grid[0][i];
        }

        long result = long.MaxValue;
        long bottomSoFar = 0;

        for (int i = 0; i < n; i++) {
            // First robot passes through column i
            topSum -= grid[0][i];       // remaining top-right
            long topRight = topSum;
            long bottomLeft = bottomSoFar;

            long secondRobot = Math.Max(topRight, bottomLeft);
            result = Math.Min(result, secondRobot);

            bottomSoFar += grid[1][i];
        }

        return result;
    }
}
