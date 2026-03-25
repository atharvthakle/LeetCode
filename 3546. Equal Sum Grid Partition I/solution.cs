public class Solution {
    public bool CanPartitionGrid(int[][] grid) {
        int m = grid.Length;
        int n = grid[0].Length;

        long total = 0;

        // total sum
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        if (total % 2 != 0) return false;

        long target = total / 2;

        // check horizontal cuts
        long curr = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                curr += grid[i][j];
            }
            if (curr == target) return true;
        }

        // check vertical cuts
        curr = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                curr += grid[i][j];
            }
            if (curr == target) return true;
        }

        return false;
    }
}
