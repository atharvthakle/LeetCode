void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int rows = boardSize;
    int cols = *boardColSize;

    int dirs[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    // Step 1: Determine the next state (encode changes)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int liveNeighbors = 0;

            // Count live neighbors
            for (int d = 0; d < 8; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                    if (board[ni][nj] == 1 || board[ni][nj] == 2)
                        liveNeighbors++;
                }
            }

            // Apply rules using temporary encodings
            if (board[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3)
                    board[i][j] = 2; // live → dead
            } else {
                if (liveNeighbors == 3)
                    board[i][j] = 3; // dead → live
            }
        }
    }

    // Step 2: Finalize states (decode back to 0 or 1)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 2) board[i][j] = 0;
            if (board[i][j] == 3) board[i][j] = 1;
        }
    }
}
