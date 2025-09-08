#include <stdlib.h>

// Helper function to build the tree
struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int postStart, int postEnd,
                       int* inorderIndex) {
    if (inStart > inEnd || postStart > postEnd) return NULL;

    int rootVal = postorder[postEnd];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    int inRootIndex = inorderIndex[rootVal + 3000]; // handle negative values
    int leftSize = inRootIndex - inStart;

    root->left = build(inorder, inStart, inRootIndex - 1,
                       postorder, postStart, postStart + leftSize - 1,
                       inorderIndex);
    root->right = build(inorder, inRootIndex + 1, inEnd,
                        postorder, postStart + leftSize, postEnd - 1,
                        inorderIndex);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int* inorderIndex = (int*)malloc(sizeof(int) * 6001); // for values -3000..3000
    for (int i = 0; i < inorderSize; i++) {
        inorderIndex[inorder[i] + 3000] = i;
    }

    struct TreeNode* root = build(inorder, 0, inorderSize - 1,
                                  postorder, 0, postorderSize - 1,
                                  inorderIndex);
    free(inorderIndex);
    return root;
}
