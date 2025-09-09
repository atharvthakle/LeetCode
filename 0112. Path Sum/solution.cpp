class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;  // empty tree
        
        // If it's a leaf node, check if sum matches
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        
        // Recurse on children with updated target
        int newTarget = targetSum - root->val;
        return hasPathSum(root->left, newTarget) || hasPathSum(root->right, newTarget);
    }
};
