/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;

    // We’ll use BFS (queue)
    struct TreeNode* queue[200];  // enough for 100 nodes safely
    int front = 0, rear = 0;

    int* result = (int*)malloc(100 * sizeof(int)); // maximum 100 nodes in the tree

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        int lastValue = 0;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            lastValue = node->val; // keep updating; last node in level will remain

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        result[*returnSize] = lastValue;
        (*returnSize)++;
    }

    return result;
}
