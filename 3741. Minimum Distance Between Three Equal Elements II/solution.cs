using System;
using System.Collections.Generic;

public class Solution {
    public int MinimumDistance(int[] nums) {
        var map = new Dictionary<int, List<int>>();
        
        // collect indices
        for (int i = 0; i < nums.Length; i++) {
            if (!map.ContainsKey(nums[i])) {
                map[nums[i]] = new List<int>();
            }
            map[nums[i]].Add(i);
        }

        int res = int.MaxValue;

        foreach (var kv in map) {
            var pos = kv.Value;

            if (pos.Count < 3) continue;

            for (int i = 0; i + 2 < pos.Count; i++) {
                int dist = 2 * (pos[i + 2] - pos[i]);
                res = Math.Min(res, dist);
            }
        }

        return res == int.MaxValue ? -1 : res;
    }
}
