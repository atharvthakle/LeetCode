public class Solution {
    public int KthSmallest(int[][] matrix, int k) {
        int n = matrix.Length;
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (CountLessEqual(matrix, mid) < k)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }

    private int CountLessEqual(int[][] matrix, int target) {
        int n = matrix.Length;
        int row = n - 1;
        int col = 0;
        int count = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }

        return count;
    }
}
