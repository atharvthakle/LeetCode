void dfs(char** board, int i, int j, int boardSize, int boardColSize) {
    if (i < 0 || j < 0 || i >= boardSize || j >= boardColSize || board[i][j] != 'O')
        return;

    board[i][j] = 'S'; // mark as safe

    dfs(board, i + 1, j, boardSize, boardColSize);
    dfs(board, i - 1, j, boardSize, boardColSize);
    dfs(board, i, j + 1, boardSize, boardColSize);
    dfs(board, i, j - 1, boardSize, boardColSize);
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0) return;
    int cols = *boardColSize;

    // Step 1: DFS from 'O's on the borders
    for (int i = 0; i < boardSize; i++) {
        if (board[i][0] == 'O') dfs(board, i, 0, boardSize, cols);
        if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1, boardSize, cols);
    }
    for (int j = 0; j < cols; j++) {
        if (board[0][j] == 'O') dfs(board, 0, j, boardSize, cols);
        if (board[boardSize - 1][j] == 'O') dfs(board, boardSize - 1, j, boardSize, cols);
    }

    // Step 2: Flip all remaining 'O' to 'X' and safe 'S' back to 'O'
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == 'S') board[i][j] = 'O';
        }
    }
}
