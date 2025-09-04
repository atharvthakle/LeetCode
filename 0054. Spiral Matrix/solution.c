#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int m = matrixSize;
    int n = *matrixColSize;
    int* result = (int*)malloc(sizeof(int) * m * n);
    *returnSize = 0;
    
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    
    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int j = left; j <= right; j++) {
            result[(*returnSize)++] = matrix[top][j];
        }
        top++;
        
        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;
        
        if (top <= bottom) {
            // Traverse from right to left
            for (int j = right; j >= left; j--) {
                result[(*returnSize)++] = matrix[bottom][j];
            }
            bottom--;
        }
        
        if (left <= right) {
            // Traverse from bottom to top
            for (int i = bottom; i >= top; i--) {
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
    }
    
    return result;
}  
