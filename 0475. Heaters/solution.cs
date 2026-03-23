public class Solution {
    public int FindRadius(int[] houses, int[] heaters) {
        Array.Sort(houses);
        Array.Sort(heaters);

        int radius = 0;

        foreach (int house in houses) {
            int idx = Array.BinarySearch(heaters, house);

            if (idx >= 0) {
                // exact match → distance = 0
                continue;
            }

            idx = ~idx; // insertion point

            int leftDist = int.MaxValue;
            int rightDist = int.MaxValue;

            if (idx - 1 >= 0)
                leftDist = house - heaters[idx - 1];

            if (idx < heaters.Length)
                rightDist = heaters[idx] - house;

            int nearest = Math.Min(leftDist, rightDist);
            radius = Math.Max(radius, nearest);
        }

        return radius;
    }
}
