import java.util.*;

class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration,
                                  int[] waterStartTime, int[] waterDuration) {

        long ans = Math.min(
            solve(landStartTime, landDuration, waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration, landStartTime, landDuration)
        );

        return (int) ans;
    }

    private long solve(int[] startA, int[] durA,
                       int[] startB, int[] durB) {

        int m = startB.length;

        int[][] rides = new int[m][2];
        for (int i = 0; i < m; i++) {
            rides[i][0] = startB[i];
            rides[i][1] = durB[i];
        }

        Arrays.sort(rides, Comparator.comparingInt(a -> a[0]));

        int[] starts = new int[m];
        long[] prefixMinDur = new long[m];
        long[] suffixMinFinish = new long[m];

        for (int i = 0; i < m; i++) {
            starts[i] = rides[i][0];
        }

        prefixMinDur[0] = rides[0][1];
        for (int i = 1; i < m; i++) {
            prefixMinDur[i] = Math.min(prefixMinDur[i - 1], rides[i][1]);
        }

        suffixMinFinish[m - 1] = (long) rides[m - 1][0] + rides[m - 1][1];
        for (int i = m - 2; i >= 0; i--) {
            suffixMinFinish[i] = Math.min(
                suffixMinFinish[i + 1],
                (long) rides[i][0] + rides[i][1]
            );
        }

        long best = Long.MAX_VALUE;

        for (int i = 0; i < startA.length; i++) {
            long t = (long) startA[i] + durA[i];

            int idx = upperBound(starts, (int) t) - 1;

            long cur = Long.MAX_VALUE;

            // rides already open when first ride ends
            if (idx >= 0) {
                cur = Math.min(cur, t + prefixMinDur[idx]);
            }

            // rides opening later
            if (idx + 1 < m) {
                cur = Math.min(cur, suffixMinFinish[idx + 1]);
            }

            best = Math.min(best, cur);
        }

        return best;
    }

    private int upperBound(int[] arr, int target) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
}
