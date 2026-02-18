using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> LevelOrder(Node root) {
        IList<IList<int>> result = new List<IList<int>>();
        if (root == null) return result;

        Queue<Node> queue = new Queue<Node>();
        queue.Enqueue(root);

        while (queue.Count > 0) {
            int levelSize = queue.Count;
            List<int> level = new List<int>();

            for (int i = 0; i < levelSize; i++) {
                Node current = queue.Dequeue();
                level.Add(current.val);

                if (current.children != null) {
                    foreach (Node child in current.children) {
                        queue.Enqueue(child);
                    }
                }
            }

            result.Add(level);
        }

        return result;
    }
}
