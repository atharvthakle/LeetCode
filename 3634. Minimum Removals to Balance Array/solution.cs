using System;

public class Solution {
    public int MinRemoval(int[] nums, int k) {
        int n = nums.Length;
        Array.Sort(nums);

        int maxKeep = 1;
        int left = 0;

        for (int right = 0; right < n; right++) {
            // Shrink window until condition holds
            while (left <= right && (long)nums[right] > (long)nums[left] * k) {
                left++;
            }

            // Update maximum valid window size
            maxKeep = Math.Max(maxKeep, right - left + 1);
        }

        // Minimum removals
        return n - maxKeep;
    }
}
