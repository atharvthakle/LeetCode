public class Solution {
    public int NumberOfArithmeticSlices(int[] nums) {
        int n = nums.Length;
        if (n < 3) return 0;

        int curr = 0;
        int total = 0;

        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                curr++;
                total += curr;
            } else {
                curr = 0;
            }
        }

        return total;
    }
}
