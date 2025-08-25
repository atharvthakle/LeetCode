#include <stdlib.h>

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int m = matSize;
    int n = matColSize[0];
    int total = m * n;
    *returnSize = total;

    int* result = (int*)malloc(total * sizeof(int));
    int r = 0, c = 0, dir = 1; // dir = 1 (up-right), dir = -1 (down-left)

    for (int i = 0; i < total; i++) {
        result[i] = mat[r][c];

        if (dir == 1) { // moving up-right
            if (c == n - 1) {  // hit right boundary
                r++;
                dir = -1;
            } else if (r == 0) { // hit top boundary
                c++;
                dir = -1;
            } else { // normal move
                r--;
                c++;
            }
        } else { // moving down-left
            if (r == m - 1) { // hit bottom boundary
                c++;
                dir = 1;
            } else if (c == 0) { // hit left boundary
                r++;
                dir = 1;
            } else { // normal move
                r++;
                c--;
            }
        }
    }

    return result;
}
