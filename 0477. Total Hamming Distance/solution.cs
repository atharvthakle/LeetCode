public class Solution {
    public int TotalHammingDistance(int[] nums) {
        int n = nums.Length;
        int total = 0;

        for (int bit = 0; bit < 32; bit++) {
            int ones = 0;

            foreach (int num in nums) {
                if (((num >> bit) & 1) == 1) {
                    ones++;
                }
            }

            int zeros = n - ones;
            total += ones * zeros;
        }

        return total;
    }
}
