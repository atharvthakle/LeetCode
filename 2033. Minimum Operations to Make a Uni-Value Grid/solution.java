import java.util.*;

class Solution {
    public int minOperations(int[][] grid, int x) {
        List<Integer> list = new ArrayList<>();

        // flatten grid
        for (int[] row : grid) {
            for (int val : row) {
                list.add(val);
            }
        }

        // check feasibility
        int base = list.get(0);
        for (int val : list) {
            if ((val - base) % x != 0) {
                return -1;
            }
        }

        // sort
        Collections.sort(list);

        // median
        int median = list.get(list.size() / 2);

        // compute operations
        int ops = 0;
        for (int val : list) {
            ops += Math.abs(val - median) / x;
        }

        return ops;
    }
}
