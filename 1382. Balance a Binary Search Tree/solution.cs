public class Solution {
    public TreeNode BalanceBST(TreeNode root) {
        // Step 1: Inorder traversal to get sorted values
        List<int> values = new List<int>();
        Inorder(root, values);
        
        // Step 2: Build balanced BST from sorted values
        return BuildBalanced(values, 0, values.Count - 1);
    }

    private void Inorder(TreeNode node, List<int> values) {
        if (node == null) return;
        Inorder(node.left, values);
        values.Add(node.val);
        Inorder(node.right, values);
    }

    private TreeNode BuildBalanced(List<int> values, int left, int right) {
        if (left > right) return null;

        int mid = left + (right - left) / 2;
        TreeNode node = new TreeNode(values[mid]);
        
        node.left = BuildBalanced(values, left, mid - 1);
        node.right = BuildBalanced(values, mid + 1, right);
        
        return node;
    }
}
