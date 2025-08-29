#include <stdio.h>
#include <stdlib.h>

// comparator for ascending
int cmpAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// comparator for descending
int cmpDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int** sortMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    
    // allocate result
    int** res = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            res[i][j] = grid[i][j]; // copy original
        }
    }

    // process diagonals starting from first column
    for (int row = 0; row < n; row++) {
        int len = 0;
        int temp[20]; // n <= 10, safe
        int i = row, j = 0;
        while (i < n && j < n) {
            temp[len++] = res[i][j];
            i++; j++;
        }
        if (row == 0) {
            // main diagonal -> non-increasing
            qsort(temp, len, sizeof(int), cmpDesc);
        } else {
            // bottom-left -> non-increasing
            qsort(temp, len, sizeof(int), cmpDesc);
        }
        i = row; j = 0;
        for (int k = 0; k < len; k++) {
            res[i][j] = temp[k];
            i++; j++;
        }
    }

    // process diagonals starting from first row (excluding main diagonal)
    for (int col = 1; col < n; col++) {
        int len = 0;
        int temp[20];
        int i = 0, j = col;
        while (i < n && j < n) {
            temp[len++] = res[i][j];
            i++; j++;
        }
        // top-right -> non-decreasing
        qsort(temp, len, sizeof(int), cmpAsc);
        i = 0; j = col;
        for (int k = 0; k < len; k++) {
            res[i][j] = temp[k];
            i++; j++;
        }
    }

    *returnSize = n;
    return res;
}
