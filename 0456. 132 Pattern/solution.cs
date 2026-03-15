using System.Collections.Generic;

public class Solution {
    public bool Find132pattern(int[] nums) {
        int third = int.MinValue;
        Stack<int> stack = new Stack<int>();

        for (int i = nums.Length - 1; i >= 0; i--) {
            if (nums[i] < third)
                return true;

            while (stack.Count > 0 && nums[i] > stack.Peek()) {
                third = stack.Pop();
            }

            stack.Push(nums[i]);
        }

        return false;
    }
}
