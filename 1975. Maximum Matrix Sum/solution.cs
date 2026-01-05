public class Solution {
    public long MaxMatrixSum(int[][] matrix) {
        long total = 0;
        int negCount = 0;
        int minAbs = int.MaxValue;

        foreach (var row in matrix) {
            foreach (int val in row) {
                if (val < 0) negCount++;
                int absVal = Math.Abs(val);
                total += absVal;
                minAbs = Math.Min(minAbs, absVal);
            }
        }

        // If odd number of negatives, one must remain negative
        if (negCount % 2 == 1) {
            total -= 2L * minAbs;
        }

        return total;
    }
}
