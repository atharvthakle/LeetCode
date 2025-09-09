/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* node, int current) {
    if (!node) return 0;

    // Update current number
    current = current * 10 + node->val;

    // If it's a leaf, return the formed number
    if (!node->left && !node->right) {
        return current;
    }

    // Otherwise, recurse on children
    return dfs(node->left, current) + dfs(node->right, current);
}

int sumNumbers(struct TreeNode* root) {
    if (!root) return 0;
    return dfs(root, 0);
}
