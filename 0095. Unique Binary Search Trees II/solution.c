#include <stdlib.h>

// Helper to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive helper to generate all BSTs from start to end
struct TreeNode** generate(int start, int end, int* returnSize) {
    if (start > end) {
        struct TreeNode** list = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        list[0] = NULL;
        *returnSize = 1;
        return list;
    }

    struct TreeNode** list = NULL;
    int count = 0;

    for (int i = start; i <= end; i++) {
        int leftSize = 0, rightSize = 0;
        struct TreeNode** leftTrees = generate(start, i - 1, &leftSize);
        struct TreeNode** rightTrees = generate(i + 1, end, &rightSize);

        // Allocate/resize list dynamically
        list = (struct TreeNode**)realloc(list, sizeof(struct TreeNode*) * (count + leftSize * rightSize));

        for (int l = 0; l < leftSize; l++) {
            for (int r = 0; r < rightSize; r++) {
                struct TreeNode* root = newNode(i);
                root->left = leftTrees[l];
                root->right = rightTrees[r];
                list[count++] = root;
            }
        }

        free(leftTrees);
        free(rightTrees);
    }

    *returnSize = count;
    return list;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generate(1, n, returnSize);
}
