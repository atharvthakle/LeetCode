public class Solution {
    public int MaxLevelSum(TreeNode root) {
        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        int level = 1;
        int bestLevel = 1;
        long maxSum = long.MinValue;

        while (queue.Count > 0) {
            int size = queue.Count;
            long sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.Dequeue();
                sum += node.val;

                if (node.left != null)
                    queue.Enqueue(node.left);
                if (node.right != null)
                    queue.Enqueue(node.right);
            }

            if (sum > maxSum) {
                maxSum = sum;
                bestLevel = level;
            }

            level++;
        }

        return bestLevel;
    }
}
