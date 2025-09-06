#include <stdbool.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode* root, long minVal, long maxVal) {
    if (root == NULL) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return helper(root->left, minVal, root->val) && 
           helper(root->right, root->val, maxVal);
}

bool isValidBST(struct TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}
