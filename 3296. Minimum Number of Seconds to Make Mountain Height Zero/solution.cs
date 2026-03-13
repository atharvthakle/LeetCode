public class Solution {
    public long MinNumberOfSeconds(int mountainHeight, int[] workerTimes) {
        long left = 0;
        long right = (long)1e18;
        long ans = right;

        while (left <= right) {
            long mid = (left + right) / 2;

            if (Can(mid, mountainHeight, workerTimes)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }

    private bool Can(long time, int mountainHeight, int[] workerTimes) {
        long total = 0;

        foreach (int t in workerTimes) {
            long low = 0, high = 200000;

            while (low <= high) {
                long mid = (low + high) / 2;
                long cost = (long)t * mid * (mid + 1) / 2;

                if (cost <= time) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            total += high;
            if (total >= mountainHeight) return true;
        }

        return false;
    }
}
