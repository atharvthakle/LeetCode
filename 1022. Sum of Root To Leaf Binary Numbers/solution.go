func sumRootToLeaf(root *TreeNode) int {
    return dfs(root, 0)
}

func dfs(node *TreeNode, curr int) int {
    if node == nil {
        return 0
    }

    // Build binary number
    curr = (curr << 1) | node.Val

    // If leaf node, return value
    if node.Left == nil && node.Right == nil {
        return curr
    }

    // Sum from left and right
    return dfs(node.Left, curr) + dfs(node.Right, curr)
}
