using System;
using System.Collections.Generic;

public class Solution {
    public int[][] MinAbsDiff(int[][] grid, int k) {
        int m = grid.Length;
        int n = grid[0].Length;

        int rows = m - k + 1;
        int cols = n - k + 1;

        int[][] ans = new int[rows][];
        for (int i = 0; i < rows; i++) {
            ans[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                HashSet<int> set = new HashSet<int>();

                // Collect unique values in k x k submatrix
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        set.Add(grid[x][y]);
                    }
                }

                // If only one distinct value → answer = 0
                if (set.Count <= 1) {
                    ans[i][j] = 0;
                    continue;
                }

                List<int> values = new List<int>(set);
                values.Sort();

                int minDiff = int.MaxValue;

                for (int t = 1; t < values.Count; t++) {
                    int diff = values[t] - values[t - 1];
                    if (diff < minDiff) {
                        minDiff = diff;
                    }
                }

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
}
