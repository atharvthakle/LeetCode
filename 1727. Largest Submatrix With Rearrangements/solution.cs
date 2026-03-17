using System;

public class Solution {
    public int LargestSubmatrix(int[][] matrix) {
        int m = matrix.Length;
        int n = matrix[0].Length;
        
        int[] height = new int[n];
        int maxArea = 0;

        for (int i = 0; i < m; i++) {

            // update heights
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0)
                    height[j] = 0;
                else
                    height[j]++;
            }

            int[] sorted = (int[])height.Clone();
            Array.Sort(sorted);
            Array.Reverse(sorted);

            for (int k = 0; k < n; k++) {
                int area = sorted[k] * (k + 1);
                maxArea = Math.Max(maxArea, area);
            }
        }

        return maxArea;
    }
}
