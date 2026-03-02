using System.Collections.Generic;

public class Solution {
    public int NumberOfBoomerangs(int[][] points) {
        int n = points.Length;
        int total = 0;

        for (int i = 0; i < n; i++) {
            Dictionary<long, int> map = new Dictionary<long, int>();

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long dx = points[i][0] - points[j][0];
                long dy = points[i][1] - points[j][1];
                long dist = dx * dx + dy * dy;

                if (!map.ContainsKey(dist))
                    map[dist] = 0;

                map[dist]++;
            }

            // Count permutations
            foreach (var count in map.Values) {
                total += count * (count - 1);
            }
        }

        return total;
    }
}
