public class Solution {
    public long MinimumCost(string source, string target, char[] original, char[] changed, int[] cost) {
        const int INF = int.MaxValue / 4;
        int[][] dist = new int[26][];
        for (int i = 0; i < 26; i++) {
            dist[i] = new int[26];
            for (int j = 0; j < 26; j++)
                dist[i][j] = (i == j) ? 0 : INF;
        }

        // Apply given direct transformations (keep minimum if duplicates exist)
        for (int i = 0; i < original.Length; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = Math.Min(dist[u][v], cost[i]);
        }

        // Floyd–Warshall for all-pairs shortest conversion cost
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        long total = 0;
        int n = source.Length;

        for (int i = 0; i < n; i++) {
            char s = source[i];
            char t = target[i];
            if (s == t) continue;

            int c = dist[s - 'a'][t - 'a'];
            if (c >= INF) return -1; // impossible conversion
            total += c;
        }

        return total;
    }
}
