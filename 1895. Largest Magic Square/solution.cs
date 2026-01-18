public class Solution {
    public int LargestMagicSquare(int[][] grid) {
        int m = grid.Length;
        int n = grid[0].Length;

        // Prefix sums for rows
        int[][] rowPref = new int[m][];
        int[][] colPref = new int[m][];
        int[][] diag1 = new int[m][];
        int[][] diag2 = new int[m][];

        for (int i = 0; i < m; i++) {
            rowPref[i] = new int[n + 1];
            colPref[i] = new int[n + 1];
            diag1[i] = new int[n + 1];
            diag2[i] = new int[n + 1];
        }

        // Build prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowPref[i][j + 1] = rowPref[i][j] + grid[i][j];
                colPref[i][j + 1] = colPref[i][j] + grid[j][i]; 
            }
        }

        // Diagonal prefixes
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diag1[i][j] = grid[i][j] + (i > 0 && j > 0 ? diag1[i - 1][j - 1] : 0);
                diag2[i][j] = grid[i][j] + (i > 0 && j + 1 < n ? diag2[i - 1][j + 1] : 0);
            }
        }

        // Try largest k first
        int maxK = Math.Min(m, n);
        for (int k = maxK; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (IsMagic(grid, rowPref, colPref, diag1, diag2, i, j, k))
                        return k;
                }
            }
        }

        return 1; // Every 1x1 is magic
    }

    private bool IsMagic(int[][] grid, int[][] rowPref, int[][] colPref, 
                          int[][] diag1, int[][] diag2, int r, int c, int k) {

        int target = rowPref[r][c + k] - rowPref[r][c];

        // Check rows
        for (int i = r; i < r + k; i++) {
            int sum = rowPref[i][c + k] - rowPref[i][c];
            if (sum != target) return false;
        }

        // Check columns
        for (int j = c; j < c + k; j++) {
            int sum = colPref[j][r + k] - colPref[j][r];
            if (sum != target) return false;
        }

        // Check main diagonal
        int d1 = diag1[r + k - 1][c + k - 1] - (r > 0 && c > 0 ? diag1[r - 1][c - 1] : 0);
        if (d1 != target) return false;

        // Check anti-diagonal
        int d2 = diag2[r + k - 1][c] - (r > 0 && c + k < grid[0].Length ? diag2[r - 1][c + k] : 0);
        if (d2 != target) return false;

        return true;
    }
}
