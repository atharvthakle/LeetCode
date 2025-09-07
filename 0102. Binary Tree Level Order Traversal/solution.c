#include <stdlib.h>

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // max nodes from constraints (safe upper bound)
    int MAXN = 2000;

    // BFS queue
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAXN);
    int front = 0, back = 0;

    // Result arrays
    int** result = (int**)malloc(sizeof(int*) * MAXN);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAXN);

    *returnSize = 0;

    // enqueue root
    queue[back++] = root;

    while (front < back) {
        int levelSize = back - front;

        // allocate array for this level
        int* levelVals = (int*)malloc(sizeof(int) * levelSize);

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            levelVals[i] = node->val;

            if (node->left)  queue[back++] = node->left;
            if (node->right) queue[back++] = node->right;
        }

        result[*returnSize] = levelVals;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
    }

    free(queue);
    return result;
}
