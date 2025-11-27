public class Solution {
    public long MaxSubarraySum(int[] nums, int k) {
        int n = nums.Length;
        long[] minPref = new long[k];
        for (int i = 0; i < k; i++) minPref[i] = long.MaxValue;

        long prefix = 0;
        long ans = long.MinValue;

        // prefix sum at index 0 (before processing any element)
        minPref[0] = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int r = (i + 1) % k;

            // Try using the best previous prefix with same remainder
            if (minPref[r] != long.MaxValue) {
                ans = Math.Max(ans, prefix - minPref[r]);
            }

            // Update the minimum prefix for this remainder
            minPref[r] = Math.Min(minPref[r], prefix);
        }

        return ans;
    }
}
