public class Solution {
    public int XorAfterQueries(int[] nums, int[][] queries) {
        int MOD = 1_000_000_007;

        foreach (var q in queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            for (int i = l; i <= r; i += k) {
                long val = (long)nums[i] * v;
                nums[i] = (int)(val % MOD);
            }
        }

        int xor = 0;
        foreach (int num in nums) {
            xor ^= num;
        }

        return xor;
    }
}
