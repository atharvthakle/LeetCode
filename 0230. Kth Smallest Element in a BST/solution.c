/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* k, int* result) {
    if (!root || *k == 0) return;

    // Traverse left subtree
    inorder(root->left, k, result);

    // Visit current node
    (*k)--;
    if (*k == 0) {
        *result = root->val;
        return;
    }

    // Traverse right subtree
    inorder(root->right, k, result);
}

int kthSmallest(struct TreeNode* root, int k) {
    int result = -1;
    inorder(root, &k, &result);
    return result;
}
