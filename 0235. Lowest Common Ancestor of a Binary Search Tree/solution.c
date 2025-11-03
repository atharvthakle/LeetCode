/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // Traverse the tree
    while (root != NULL) {
        // If both nodes are smaller than root, go left
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        // If both nodes are greater than root, go right
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        // Otherwise, root is the split point — the LCA
        else {
            return root;
        }
    }
    return NULL; // Just for safety; by problem constraints, this won't happen
}
