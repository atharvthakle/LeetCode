public class Solution {
    public int MinMoves(int[] nums) {
        int min = int.MaxValue;
        long sum = 0;

        foreach (int num in nums) {
            min = Math.Min(min, num);
            sum += num;
        }

        return (int)(sum - (long)min * nums.Length);
    }
}
