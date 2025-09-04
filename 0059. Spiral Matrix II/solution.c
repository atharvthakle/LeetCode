#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the matrix
    int** matrix = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = n;

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1, total = n * n;

    while (num <= total) {
        // Traverse left → right
        for (int j = left; j <= right && num <= total; j++) {
            matrix[top][j] = num++;
        }
        top++;

        // Traverse top → bottom
        for (int i = top; i <= bottom && num <= total; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // Traverse right → left
        for (int j = right; j >= left && num <= total; j--) {
            matrix[bottom][j] = num++;
        }
        bottom--;

        // Traverse bottom → top
        for (int i = bottom; i >= top && num <= total; i--) {
            matrix[i][left] = num++;
        }
        left++;
    }

    return matrix;
}
