public class Solution {
    public int MinDeletionSize(string[] strs) {
        int n = strs.Length;
        int m = strs[0].Length;
        
        bool[] sorted = new bool[n - 1];
        int deletions = 0;

        for (int col = 0; col < m; col++) {
            bool needDelete = false;

            // Check if this column breaks ordering
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                    needDelete = true;
                    break;
                }
            }

            if (needDelete) {
                deletions++;
                continue;
            }

            // Update sorted status
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] < strs[i + 1][col]) {
                    sorted[i] = true;
                }
            }
        }

        return deletions;
    }
}
