public class Solution {
    public long MinimumTime(int[] time, int totalTrips) {
        long left = 1;
        long right = (long)time.Min() * totalTrips; // upper bound

        while (left < right) {
            long mid = left + (right - left) / 2;
            long trips = 0;

            foreach (int t in time) {
                trips += mid / t;
                if (trips >= totalTrips)
                    break;
            }

            if (trips >= totalTrips)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
}
