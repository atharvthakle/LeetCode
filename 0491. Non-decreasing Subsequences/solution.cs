using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> FindSubsequences(int[] nums) {
        var result = new List<IList<int>>();
        Backtrack(0, new List<int>(), nums, result);
        return result;
    }

    private void Backtrack(int start, List<int> path, int[] nums, List<IList<int>> result) {
        if (path.Count >= 2) {
            result.Add(new List<int>(path));
        }

        HashSet<int> used = new HashSet<int>();

        for (int i = start; i < nums.Length; i++) {
            // skip duplicates at same level
            if (used.Contains(nums[i])) continue;

            // maintain non-decreasing order
            if (path.Count > 0 && nums[i] < path[path.Count - 1]) continue;

            used.Add(nums[i]);

            path.Add(nums[i]);
            Backtrack(i + 1, path, nums, result);
            path.RemoveAt(path.Count - 1);
        }
    }
}
