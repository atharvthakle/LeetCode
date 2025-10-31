/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr; // base case: empty tree

        // swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // recursively invert subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
