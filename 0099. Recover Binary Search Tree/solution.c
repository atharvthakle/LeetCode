/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* first = NULL;
struct TreeNode* second = NULL;
struct TreeNode* prev = NULL;

void inorder(struct TreeNode* root) {
    if (!root) return;

    inorder(root->left);

    if (prev && prev->val > root->val) {
        if (!first) first = prev;
        second = root;
    }
    prev = root;

    inorder(root->right);
}

void recoverTree(struct TreeNode* root) {
    first = second = prev = NULL;
    inorder(root);
    if (first && second) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}
