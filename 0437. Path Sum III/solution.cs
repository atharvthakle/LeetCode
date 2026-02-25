using System.Collections.Generic;

public class Solution {
    public int PathSum(TreeNode root, int targetSum) {
        Dictionary<long, int> prefix = new Dictionary<long, int>();
        prefix[0] = 1;  // base case
        
        return DFS(root, 0, targetSum, prefix);
    }

    private int DFS(TreeNode node, long currSum, int target, Dictionary<long, int> prefix) {
        if (node == null)
            return 0;

        currSum += node.val;

        int count = 0;

        // Check if there is a prefix sum that makes target
        if (prefix.ContainsKey(currSum - target)) {
            count += prefix[currSum - target];
        }

        // Add current prefix sum
        if (!prefix.ContainsKey(currSum))
            prefix[currSum] = 0;
        prefix[currSum]++;

        // Recurse
        count += DFS(node.left, currSum, target, prefix);
        count += DFS(node.right, currSum, target, prefix);

        // Backtrack
        prefix[currSum]--;

        return count;
    }
}
