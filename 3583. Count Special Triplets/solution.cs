public class Solution {
    private const int MOD = 1_000_000_007;

    public int SpecialTriplets(int[] nums) {
        int n = nums.Length;
        
        // Frequency map for the right side
        Dictionary<int, long> right = new Dictionary<int, long>();
        foreach (int x in nums) {
            if (!right.ContainsKey(x))
                right[x] = 0;
            right[x]++;
        }

        Dictionary<int, long> left = new Dictionary<int, long>();
        long result = 0;

        for (int j = 0; j < n; j++) {
            int mid = nums[j];
            right[mid]--;  // Move current from right to middle

            int target = mid * 2;

            if (left.ContainsKey(target) && right.ContainsKey(target)) {
                result = (result + left[target] * right[target]) % MOD;
            }

            // Add current value to left map
            if (!left.ContainsKey(mid))
                left[mid] = 0;
            left[mid]++;
        }

        return (int)result;
    }
}
