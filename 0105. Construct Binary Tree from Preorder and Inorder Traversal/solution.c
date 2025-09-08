#include <stdlib.h>

// Helper function
struct TreeNode* build(int* preorder, int preStart, int preEnd,
                       int* inorder, int inStart, int inEnd,
                       int* inorderIndex) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    int rootVal = preorder[preStart];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    int inRootIndex = inorderIndex[rootVal + 3000]; // handle negatives
    int leftSize = inRootIndex - inStart;

    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, inRootIndex - 1,
                       inorderIndex);
    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, inRootIndex + 1, inEnd,
                        inorderIndex);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int* inorderIndex = (int*)malloc(sizeof(int) * 6001); // shift by +3000 for negatives
    for (int i = 0; i < inorderSize; i++) {
        inorderIndex[inorder[i] + 3000] = i;
    }

    struct TreeNode* root = build(preorder, 0, preorderSize - 1,
                                  inorder, 0, inorderSize - 1,
                                  inorderIndex);
    free(inorderIndex);
    return root;
}
