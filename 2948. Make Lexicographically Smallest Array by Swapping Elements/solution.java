import java.util.*;

class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        int[][] pairs = new int[n][2];

        for (int i = 0; i < n; i++) {
            pairs[i][0] = nums[i];
            pairs[i][1] = i;
        }

        Arrays.sort(pairs, Comparator.comparingInt(a -> a[0]));

        int[] result = new int[n];
        int start = 0;

        while (start < n) {
            int end = start;

            // All values connected through differences <= limit
            // belong to the same swappable group.
            while (end + 1 < n &&
                    (long) pairs[end + 1][0] - pairs[end][0] <= limit) {
                end++;
            }

            List<Integer> indices = new ArrayList<>();

            for (int i = start; i <= end; i++) {
                indices.add(pairs[i][1]);
            }

            Collections.sort(indices);

            // Values are already sorted because pairs is sorted.
            for (int i = 0; i < indices.size(); i++) {
                result[indices.get(i)] = pairs[start + i][0];
            }

            start = end + 1;
        }

        return result;
    }
}
