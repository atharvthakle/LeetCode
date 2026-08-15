class Solution {
    public int longestSubsequence(int[] nums) {
        int n = nums.length;
        int xor = 0;

        for (int x : nums) {
            xor ^= x;
        }

        if (xor != 0) {
            return n;
        }

        // If total XOR is 0, remove one non-zero element.
        for (int x : nums) {
            if (x != 0) {
                return n - 1;
            }
        }

        // All elements are 0, so every subsequence has XOR 0.
        return 0;
    }
}
