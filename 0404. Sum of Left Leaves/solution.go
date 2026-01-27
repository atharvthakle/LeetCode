func sumOfLeftLeaves(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    sum := 0
    
    // Check if left child is a leaf
    if root.Left != nil && root.Left.Left == nil && root.Left.Right == nil {
        sum += root.Left.Val
    }
    
    // Recurse on both subtrees
    sum += sumOfLeftLeaves(root.Left)
    sum += sumOfLeftLeaves(root.Right)
    
    return sum
}
