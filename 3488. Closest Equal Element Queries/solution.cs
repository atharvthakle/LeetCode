using System;
using System.Collections.Generic;

public class Solution {
    public IList<int> SolveQueries(int[] nums, int[] queries) {
        int n = nums.Length;
        
        // map value -> list of indices
        var map = new Dictionary<int, List<int>>();
        for (int i = 0; i < n; i++) {
            if (!map.ContainsKey(nums[i])) {
                map[nums[i]] = new List<int>();
            }
            map[nums[i]].Add(i);
        }
        
        List<int> res = new List<int>();
        
        foreach (int q in queries) {
            var list = map[nums[q]];
            
            if (list.Count == 1) {
                res.Add(-1);
                continue;
            }
            
            int idx = list.BinarySearch(q);
            
            int best = int.MaxValue;
            
            // previous occurrence
            int prev = list[(idx - 1 + list.Count) % list.Count];
            int d1 = Math.Abs(q - prev);
            best = Math.Min(best, Math.Min(d1, n - d1));
            
            // next occurrence
            int next = list[(idx + 1) % list.Count];
            int d2 = Math.Abs(q - next);
            best = Math.Min(best, Math.Min(d2, n - d2));
            
            res.Add(best);
        }
        
        return res;
    }
}
