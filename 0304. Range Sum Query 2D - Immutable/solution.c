#include <stdlib.h>

typedef struct {
    int **prefixSum;   // 2D prefix sum array
    int rows;
    int cols;
} NumMatrix;

// Helper function to allocate 2D array
int** allocate2D(int rows, int cols) {
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    return arr;
}

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix *obj = (NumMatrix *)malloc(sizeof(NumMatrix));
    obj->rows = matrixSize;
    obj->cols = *matrixColSize;
    obj->prefixSum = allocate2D(matrixSize + 1, *matrixColSize + 1);

    // Initialize prefixSum array to 0
    for (int i = 0; i <= matrixSize; i++)
        for (int j = 0; j <= *matrixColSize; j++)
            obj->prefixSum[i][j] = 0;

    // Compute 2D prefix sum
    for (int i = 1; i <= matrixSize; i++) {
        for (int j = 1; j <= *matrixColSize; j++) {
            obj->prefixSum[i][j] = matrix[i-1][j-1] 
                                 + obj->prefixSum[i-1][j] 
                                 + obj->prefixSum[i][j-1] 
                                 - obj->prefixSum[i-1][j-1];
        }
    }

    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    // Use 2D prefix sum to calculate sum in O(1)
    return obj->prefixSum[row2+1][col2+1] 
         - obj->prefixSum[row1][col2+1] 
         - obj->prefixSum[row2+1][col1] 
         + obj->prefixSum[row1][col1];
}

void numMatrixFree(NumMatrix* obj) {
    for (int i = 0; i <= obj->rows; i++) {
        free(obj->prefixSum[i]);
    }
    free(obj->prefixSum);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 * numMatrixFree(obj);
*/
