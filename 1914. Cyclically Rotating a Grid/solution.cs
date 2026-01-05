public class Solution {
    public int[][] RotateGrid(int[][] grid, int k) {
        int m = grid.Length;
        int n = grid[0].Length;
        int layers = Math.Min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            List<int> elems = new List<int>();

            int top = layer;
            int bottom = m - 1 - layer;
            int left = layer;
            int right = n - 1 - layer;

            // Top row
            for (int j = left; j <= right; j++)
                elems.Add(grid[top][j]);

            // Right column
            for (int i = top + 1; i <= bottom; i++)
                elems.Add(grid[i][right]);

            // Bottom row
            for (int j = right - 1; j >= left; j--)
                elems.Add(grid[bottom][j]);

            // Left column
            for (int i = bottom - 1; i > top; i--)
                elems.Add(grid[i][left]);

            int len = elems.Count;
            int rot = k % len;

            // Rotate counter-clockwise
            var rotated = new List<int>();
            rotated.AddRange(elems.GetRange(rot, len - rot));
            rotated.AddRange(elems.GetRange(0, rot));

            int idx = 0;

            // Put back: Top row
            for (int j = left; j <= right; j++)
                grid[top][j] = rotated[idx++];

            // Right column
            for (int i = top + 1; i <= bottom; i++)
                grid[i][right] = rotated[idx++];

            // Bottom row
            for (int j = right - 1; j >= left; j--)
                grid[bottom][j] = rotated[idx++];

            // Left column
            for (int i = bottom - 1; i > top; i--)
                grid[i][left] = rotated[idx++];
        }

        return grid;
    }
}
