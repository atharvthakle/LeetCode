public class Solution {
    public int MinimumCost(int[] nums) {
        int n = nums.Length;
        int ans = int.MaxValue;

        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = Math.Min(ans, nums[0] + nums[i] + nums[j]);
            }
        }

        return ans;
    }
}
