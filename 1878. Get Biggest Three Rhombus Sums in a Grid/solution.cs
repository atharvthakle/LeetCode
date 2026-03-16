using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] GetBiggestThree(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        SortedSet<int> set = new SortedSet<int>();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                // radius 0 rhombus
                Add(set, grid[r][c]);

                for (int k = 1; ; k++) {
                    if (r - k < 0 || r + k >= m || c - k < 0 || c + k >= n)
                        break;

                    int sum = 0;

                    // top → right
                    for (int i = 0; i < k; i++)
                        sum += grid[r - k + i][c + i];

                    // right → bottom
                    for (int i = 0; i < k; i++)
                        sum += grid[r + i][c + k - i];

                    // bottom → left
                    for (int i = 0; i < k; i++)
                        sum += grid[r + k - i][c - i];

                    // left → top
                    for (int i = 0; i < k; i++)
                        sum += grid[r - i][c - k + i];

                    Add(set, sum);
                }
            }
        }

        return set.Reverse().Take(3).ToArray();
    }

    private void Add(SortedSet<int> set, int val) {
        set.Add(val);
        if (set.Count > 3)
            set.Remove(set.Min);
    }
}
