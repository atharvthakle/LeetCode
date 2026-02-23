using System;
using System.Collections.Generic;

public class Solution {
    public bool HasAllCodes(string s, int k) {
        int n = s.Length;
        if (n < k) return false;

        int totalNeeded = 1 << k;
        if (n - k + 1 < totalNeeded) return false;

        HashSet<int> seen = new HashSet<int>();
        int mask = 0;

        // Build first window
        for (int i = 0; i < k; i++) {
            mask = (mask << 1) | (s[i] - '0');
        }
        seen.Add(mask);

        int allOnesMask = (1 << k) - 1;

        for (int i = k; i < n; i++) {
            // Remove leftmost bit and add new bit
            mask = ((mask << 1) & allOnesMask) | (s[i] - '0');
            seen.Add(mask);

            if (seen.Count == totalNeeded)
                return true;
        }

        return seen.Count == totalNeeded;
    }
}
