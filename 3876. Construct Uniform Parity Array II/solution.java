class Solution {
    public boolean uniformArray(int[] nums1) {
        int min = Integer.MAX_VALUE;
        boolean hasOdd = false;

        for (int x : nums1) {
            min = Math.min(min, x);
            if ((x & 1) == 1) {
                hasOdd = true;
            }
        }

        // If the minimum is odd, every element can be made odd.
        // If the minimum is even, it is only possible when all are even.
        return (min & 1) == 1 || !hasOdd;
    }
}
