int minimumArea(int** grid, int gridSize, int* gridColSize) {
    int minRow = gridSize, maxRow = -1;
    int minCol = *gridColSize, maxCol = -1;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                if (i < minRow) minRow = i;
                if (i > maxRow) maxRow = i;
                if (j < minCol) minCol = j;
                if (j > maxCol) maxCol = j;
            }
        }
    }

    int height = maxRow - minRow + 1;
    int width = maxCol - minCol + 1;

    return height * width;
}
