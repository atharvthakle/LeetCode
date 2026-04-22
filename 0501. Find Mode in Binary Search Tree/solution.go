func findMode(root *TreeNode) []int {
    var res []int
    var prev *int
    count := 0
    maxCount := 0

    var inorder func(node *TreeNode)
    inorder = func(node *TreeNode) {
        if node == nil {
            return
        }

        inorder(node.Left)

        // process current node
        if prev != nil && *prev == node.Val {
            count++
        } else {
            count = 1
        }

        if count > maxCount {
            maxCount = count
            res = []int{node.Val}
        } else if count == maxCount {
            res = append(res, node.Val)
        }

        val := node.Val
        prev = &val

        inorder(node.Right)
    }

    inorder(root)
    return res
}
