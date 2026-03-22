using System;

public class Solution {
    public bool Makesquare(int[] matchsticks) {
        int sum = 0;
        foreach (int x in matchsticks) sum += x;

        if (sum % 4 != 0) return false;

        int side = sum / 4;

        Array.Sort(matchsticks);
        Array.Reverse(matchsticks); // descending

        int[] sides = new int[4];

        return DFS(matchsticks, 0, sides, side);
    }

    private bool DFS(int[] nums, int index, int[] sides, int target) {
        if (index == nums.Length) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }

        int val = nums[index];

        for (int i = 0; i < 4; i++) {
            if (sides[i] + val > target) continue;

            sides[i] += val;

            if (DFS(nums, index + 1, sides, target))
                return true;

            sides[i] -= val;

            // pruning: avoid duplicate states
            if (sides[i] == 0) break;
        }

        return false;
    }
}
