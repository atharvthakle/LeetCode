public class Solution {
    public int MaxRotateFunction(int[] nums) {
        int n = nums.Length;
        long sum = 0;      // sum of all elements
        long f0 = 0;       // F(0)

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f0 += (long)i * nums[i];
        }

        long max = f0;
        long curr = f0;

        // Recurrence:
        // F(k) = F(k-1) + sum - n * nums[n-k]
        for (int k = 1; k < n; k++) {
            curr = curr + sum - (long)n * nums[n - k];
            if (curr > max) max = curr;
        }

        return (int)max;
    }
}
