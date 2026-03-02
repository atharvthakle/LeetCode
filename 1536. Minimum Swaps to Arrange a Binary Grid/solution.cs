public class Solution {
    public int MinSwaps(int[][] grid) {
        int n = grid.Length;
        int[] trailingZeros = new int[n];

        // Step 1: count trailing zeros
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                count++;
            }
            trailingZeros[i] = count;
        }

        int swaps = 0;

        // Step 2: greedy arrangement
        for (int i = 0; i < n; i++) {
            int needed = n - 1 - i;
            int j = i;

            // Find a suitable row
            while (j < n && trailingZeros[j] < needed) {
                j++;
            }

            if (j == n) {
                return -1;
            }

            // Bubble up row j to position i
            while (j > i) {
                int temp = trailingZeros[j];
                trailingZeros[j] = trailingZeros[j - 1];
                trailingZeros[j - 1] = temp;
                swaps++;
                j--;
            }
        }

        return swaps;
    }
}
