public class Solution {
    public TreeNode SubtreeWithAllDeepest(TreeNode root) {
        return Dfs(root).node;
    }

    private (TreeNode node, int depth) Dfs(TreeNode root) {
        if (root == null)
            return (null, 0);

        var left = Dfs(root.left);
        var right = Dfs(root.right);

        if (left.depth == right.depth) {
            // Deepest nodes are split across both sides
            return (root, left.depth + 1);
        } else if (left.depth > right.depth) {
            return (left.node, left.depth + 1);
        } else {
            return (right.node, right.depth + 1);
        }
    }
}
