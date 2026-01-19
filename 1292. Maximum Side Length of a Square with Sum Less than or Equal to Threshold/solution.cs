public class Solution {
    public int MaxSideLength(int[][] mat, int threshold) {
        int m = mat.Length;
        int n = mat[0].Length;

        // Build prefix sum
        int[,] pref = new int[m + 1, n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i, j] = mat[i - 1][j - 1]
                           + pref[i - 1, j]
                           + pref[i, j - 1]
                           - pref[i - 1, j - 1];
            }
        }

        // Function to get sum of submatrix (r,c) size k
        int GetSum(int r, int c, int k) {
            int r2 = r + k;
            int c2 = c + k;
            return pref[r2, c2]
                 - pref[r, c2]
                 - pref[r2, c]
                 + pref[r, c];
        }

        int low = 0, high = Math.Min(m, n);

        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (ExistsSquare(mid)) low = mid;
            else high = mid - 1;
        }

        return low;

        bool ExistsSquare(int k) {
            if (k == 0) return true;
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (GetSum(i, j, k) <= threshold)
                        return true;
                }
            }
            return false;
        }
    }
}
