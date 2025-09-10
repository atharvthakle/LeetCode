void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;
    
    while (curr != NULL) {
        if (curr->left != NULL) {
            // Find rightmost node in left subtree
            struct TreeNode* prev = curr->left;
            while (prev->right != NULL) {
                prev = prev->right;
            }
            // Connect right subtree
            prev->right = curr->right;
            // Move left subtree to right
            curr->right = curr->left;
            curr->left = NULL;
        }
        // Move to the next node
        curr = curr->right;
    }
}
