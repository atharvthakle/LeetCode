/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

#define MAXN 2000

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Queue for BFS
    struct TreeNode* queue[MAXN];
    int front = 0, rear = 0;

    // Temporary storage for levels
    int** levels = (int**)malloc(sizeof(int*) * MAXN);
    int* colSizes = (int*)malloc(sizeof(int) * MAXN);
    int levelCount = 0;

    // Start BFS
    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;
        int* level = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            level[i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        levels[levelCount] = level;
        colSizes[levelCount] = size;
        levelCount++;
    }

    // Reverse levels
    int** result = (int**)malloc(sizeof(int*) * levelCount);
    int* resultColSizes = (int*)malloc(sizeof(int) * levelCount);

    for (int i = 0; i < levelCount; i++) {
        result[i] = levels[levelCount - 1 - i];
        resultColSizes[i] = colSizes[levelCount - 1 - i];
    }

    free(levels);
    free(colSizes);

    *returnSize = levelCount;
    *returnColumnSizes = resultColSizes;
    return result;
}
