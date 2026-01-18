public class Solution {
    public int LargestMagicSquare(int[][] grid) {
        int m = grid.Length;
        int n = grid[0].Length;

        // Prefix sums for rows
        int[][] rowPref = new int[m][];
        for (int i = 0; i < m; i++) {
            rowPref[i] = new int[n + 1];
            for (int j = 0; j < n; j++) {
                rowPref[i][j + 1] = rowPref[i][j] + grid[i][j];
            }
        }

        // Prefix sums for columns
        int[][] colPref = new int[n][];
        for (int j = 0; j < n; j++) {
            colPref[j] = new int[m + 1];
            for (int i = 0; i < m; i++) {
                colPref[j][i + 1] = colPref[j][i] + grid[i][j];
            }
        }

        int maxK = Math.Min(m, n);

        for (int k = maxK; k >= 2; k--) {
            for (int r = 0; r + k <= m; r++) {
                for (int c = 0; c + k <= n; c++) {
                    if (IsMagic(grid, rowPref, colPref, r, c, k))
                        return k;
                }
            }
        }

        return 1;
    }

    private bool IsMagic(int[][] grid, int[][] rowPref, int[][] colPref,
                          int r, int c, int k) {
        // target sum = first row
        int target = rowPref[r][c + k] - rowPref[r][c];

        // Check all rows
        for (int i = r; i < r + k; i++) {
            if (rowPref[i][c + k] - rowPref[i][c] != target)
                return false;
        }

        // Check all columns
        for (int j = c; j < c + k; j++) {
            if (colPref[j][r + k] - colPref[j][r] != target)
                return false;
        }

        // Check main diagonal
        int diag1 = 0;
        for (int i = 0; i < k; i++)
            diag1 += grid[r + i][c + i];
        if (diag1 != target) return false;

        // Check anti diagonal
        int diag2 = 0;
        for (int i = 0; i < k; i++)
            diag2 += grid[r + i][c + k - 1 - i];
        if (diag2 != target) return false;

        return true;
    }
}
