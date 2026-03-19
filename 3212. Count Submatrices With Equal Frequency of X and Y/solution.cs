public class Solution {
    public int NumberOfSubmatrices(char[][] grid) {
        int m = grid.Length;
        int n = grid[0].Length;

        int[,] px = new int[m, n];
        int[,] py = new int[m, n];

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int isX = grid[i][j] == 'X' ? 1 : 0;
                int isY = grid[i][j] == 'Y' ? 1 : 0;

                px[i, j] = isX;
                py[i, j] = isY;

                if (i > 0) {
                    px[i, j] += px[i - 1, j];
                    py[i, j] += py[i - 1, j];
                }

                if (j > 0) {
                    px[i, j] += px[i, j - 1];
                    py[i, j] += py[i, j - 1];
                }

                if (i > 0 && j > 0) {
                    px[i, j] -= px[i - 1, j - 1];
                    py[i, j] -= py[i - 1, j - 1];
                }

                if (px[i, j] == py[i, j] && px[i, j] > 0) {
                    count++;
                }
            }
        }

        return count;
    }
}
