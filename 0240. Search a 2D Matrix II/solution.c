#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return false;

    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    // Start from the top-right corner
    int row = 0;
    int col = cols - 1;
    
    // Move left or down depending on the comparison
    while (row < rows && col >= 0) {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] > target)
            col--;  // Move left
        else
            row++;  // Move down
    }
    
    return false;  // Not found
}
