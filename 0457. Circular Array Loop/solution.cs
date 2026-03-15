public class Solution {
    public bool CircularArrayLoop(int[] nums) {
        int n = nums.Length;

        int Next(int i) {
            return ((i + nums[i]) % n + n) % n;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            int slow = i, fast = i;
            bool forward = nums[i] > 0;

            while (true) {
                slow = Next(slow);
                fast = Next(fast);

                if ((nums[slow] > 0) != forward || (nums[fast] > 0) != forward)
                    break;

                fast = Next(fast);

                if ((nums[fast] > 0) != forward)
                    break;

                if (slow == fast) {
                    if (slow == Next(slow)) break; // length 1 cycle
                    return true;
                }
            }

            // mark visited nodes
            int j = i;
            while ((nums[j] > 0) == forward) {
                int next = Next(j);
                nums[j] = 0;
                if (next == j) break;
                j = next;
            }
        }

        return false;
    }
}
