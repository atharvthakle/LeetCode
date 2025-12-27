public class Solution {
    public int Rob(TreeNode root) {
        var res = Dfs(root);
        return Math.Max(res.rob, res.notRob);
    }

    // returns (rob, notRob)
    private (int rob, int notRob) Dfs(TreeNode node) {
        if (node == null) return (0, 0);

        var left = Dfs(node.left);
        var right = Dfs(node.right);

        int rob = node.val + left.notRob + right.notRob;
        int notRob = Math.Max(left.rob, left.notRob) + Math.Max(right.rob, right.notRob);

        return (rob, notRob);
    }
}
