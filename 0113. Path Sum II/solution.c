#include <stdlib.h>

// Helper to copy current path into results
void addPath(int*** res, int** colSizes, int* resSize,
             int* path, int pathLen) {
    *res = (int**)realloc(*res, (*resSize + 1) * sizeof(int*));
    (*res)[*resSize] = (int*)malloc(pathLen * sizeof(int));
    for (int i = 0; i < pathLen; i++) {
        (*res)[*resSize][i] = path[i];
    }

    *colSizes = (int*)realloc(*colSizes, (*resSize + 1) * sizeof(int));
    (*colSizes)[*resSize] = pathLen;

    (*resSize)++;
}

void dfs(struct TreeNode* root, int targetSum,
         int* path, int pathLen,
         int*** res, int** colSizes, int* resSize) {
    if (!root) return;

    path[pathLen++] = root->val;
    targetSum -= root->val;

    if (!root->left && !root->right && targetSum == 0) {
        // leaf & correct sum -> add path
        addPath(res, colSizes, resSize, path, pathLen);
    } else {
        dfs(root->left, targetSum, path, pathLen, res, colSizes, resSize);
        dfs(root->right, targetSum, path, pathLen, res, colSizes, resSize);
    }
}

int** pathSum(struct TreeNode* root, int targetSum,
              int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int** res = NULL;
    *returnColumnSizes = NULL;

    // Max path length ≤ 5000 (number of nodes)
    int* path = (int*)malloc(5000 * sizeof(int));

    dfs(root, targetSum, path, 0, &res, returnColumnSizes, returnSize);

    free(path);
    return res;
}
