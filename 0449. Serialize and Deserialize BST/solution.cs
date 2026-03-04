using System;
using System.Collections.Generic;

public class Codec {

    // Encodes a tree to a single string.
    public string serialize(TreeNode root) {
        List<int> list = new List<int>();
        Preorder(root, list);
        return string.Join(",", list);
    }

    private void Preorder(TreeNode node, List<int> list) {
        if (node == null) return;
        list.Add(node.val);
        Preorder(node.left, list);
        Preorder(node.right, list);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) {
        if (string.IsNullOrEmpty(data)) return null;

        string[] parts = data.Split(',');
        int[] preorder = new int[parts.Length];
        for (int i = 0; i < parts.Length; i++)
            preorder[i] = int.Parse(parts[i]);

        int index = 0;
        return Build(preorder, ref index, int.MinValue, int.MaxValue);
    }

    private TreeNode Build(int[] preorder, ref int index, int min, int max) {
        if (index >= preorder.Length) return null;

        int val = preorder[index];
        if (val < min || val > max) return null;

        TreeNode node = new TreeNode(val);
        index++;

        node.left = Build(preorder, ref index, min, val);
        node.right = Build(preorder, ref index, val, max);

        return node;
    }
}
