public class Solution {
    const long MOD = 1000000007;

    public int CountTrapezoids(int[][] points) {
        // Count points grouped by y-coordinate
        var map = new Dictionary<int, int>();
        foreach (var p in points) {
            int y = p[1];
            map[y] = map.GetValueOrDefault(y, 0) + 1;
        }

        // Compute C(cnt,2) for each y-level that has >=2 points
        List<long> combos = new List<long>();
        foreach (var kv in map) {
            long c = kv.Value;
            if (c >= 2)
                combos.Add((c * (c - 1) / 2) % MOD);
        }

        if (combos.Count < 2) return 0;

        // Sum of pairwise products of C(cnt,2)
        long result = 0;
        long prefixSum = 0;

        foreach (long v in combos) {
            result = (result + v * prefixSum) % MOD;
            prefixSum = (prefixSum + v) % MOD;
        }

        return (int)result;
    }
}
