public class Solution {
    private const long MOD = 1_000_000_007;
    private long totalSum = 0;
    private long maxProduct = 0;

    public int MaxProduct(TreeNode root) {
        // Step 1: compute total sum of tree
        totalSum = GetTotalSum(root);

        // Step 2: compute subtree sums and max product
        ComputeSubtreeSum(root);

        return (int)(maxProduct % MOD);
    }

    private long GetTotalSum(TreeNode node) {
        if (node == null) return 0;
        return node.val + GetTotalSum(node.left) + GetTotalSum(node.right);
    }

    private long ComputeSubtreeSum(TreeNode node) {
        if (node == null) return 0;

        long left = ComputeSubtreeSum(node.left);
        long right = ComputeSubtreeSum(node.right);

        long subSum = node.val + left + right;

        long product = subSum * (totalSum - subSum);
        maxProduct = Math.Max(maxProduct, product);

        return subSum;
    }
}
