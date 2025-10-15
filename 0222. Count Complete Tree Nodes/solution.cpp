class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);
        
        // If both heights are equal, the tree is a perfect binary tree
        if (leftHeight == rightHeight) {
            // 2^height - 1 nodes in a perfect binary tree
            return (1 << leftHeight) - 1;
        }
        
        // Otherwise, recursively count nodes in left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
private:
    int getLeftHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
    
    int getRightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};
