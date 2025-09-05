#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int boardSize, int boardColSize, int i, int j, char* word, int index) {
    if (word[index] == '\0') return true; // reached end of word
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize || board[i][j] != word[index])
        return false;

    char temp = board[i][j];
    board[i][j] = '#'; // mark visited

    bool found = dfs(board, boardSize, boardColSize, i+1, j, word, index+1) ||
                 dfs(board, boardSize, boardColSize, i-1, j, word, index+1) ||
                 dfs(board, boardSize, boardColSize, i, j+1, word, index+1) ||
                 dfs(board, boardSize, boardColSize, i, j-1, word, index+1);

    board[i][j] = temp; // unmark
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            if (dfs(board, boardSize, *boardColSize, i, j, word, 0))
                return true;
        }
    }
    return false;
}
