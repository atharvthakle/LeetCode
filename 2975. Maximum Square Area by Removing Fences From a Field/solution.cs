using System;
using System.Collections.Generic;

public class Solution {
    public int MaximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        const long MOD = 1_000_000_007;

        // Build full fence lists including borders
        var H = new List<int>(hFences);
        var V = new List<int>(vFences);
        H.Add(1);
        H.Add(m);
        V.Add(1);
        V.Add(n);

        H.Sort();
        V.Sort();

        // Store all possible horizontal spans
        HashSet<int> hSpans = new HashSet<int>();
        for (int i = 0; i < H.Count; i++) {
            for (int j = i + 1; j < H.Count; j++) {
                hSpans.Add(H[j] - H[i]);
            }
        }

        int best = 0;

        // Check vertical spans and find largest common
        for (int i = 0; i < V.Count; i++) {
            for (int j = i + 1; j < V.Count; j++) {
                int span = V[j] - V[i];
                if (hSpans.Contains(span)) {
                    if (span > best) best = span;
                }
            }
        }

        if (best == 0) return -1;

        long area = (long)best * best % MOD;
        return (int)area;
    }
}
