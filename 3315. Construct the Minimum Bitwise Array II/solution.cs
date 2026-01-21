public class Solution {
    public int[] MinBitwiseArray(IList<int> nums) {
        int n = nums.Count;
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            int p = nums[i];

            // Even p cannot be formed
            if ((p & 1) == 0) {
                ans[i] = -1;
                continue;
            }

            int best = int.MaxValue;

            // Try possible flip positions
            for (int b = 0; b < 31; b++) {
                int prefix = p >> (b + 1);
                int x = (prefix << (b + 1));
                x |= (1 << b) - 1;

                if ((x | (x + 1)) == p) {
                    if (x < best) best = x;
                }
            }

            ans[i] = best == int.MaxValue ? -1 : best;
        }

        return ans;
    }
}
