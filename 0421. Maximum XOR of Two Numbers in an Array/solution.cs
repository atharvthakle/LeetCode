using System;
using System.Collections.Generic;

public class Solution {
    public int FindMaximumXOR(int[] nums) {
        int maxXor = 0;
        int mask = 0;

        // iterate from highest bit to lowest bit
        for (int bit = 31; bit >= 0; bit--) {
            mask |= (1 << bit);

            // store prefixes
            HashSet<int> prefixes = new HashSet<int>();
            foreach (int num in nums) {
                prefixes.Add(num & mask);
            }

            // try to set this bit
            int candidate = maxXor | (1 << bit);

            // check if candidate possible
            foreach (int prefix in prefixes) {
                if (prefixes.Contains(prefix ^ candidate)) {
                    maxXor = candidate;
                    break;
                }
            }
        }

        return maxXor;
    }
}
