#include <stdbool.h>
#include <string.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    // track rows, columns, and boxes
    bool row[9][9];
    bool col[9][9];
    bool box[9][9];
    
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(box, false, sizeof(box));
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            
            int num = board[i][j] - '1';  // convert '1'..'9' → 0..8
            int boxIndex = (i / 3) * 3 + (j / 3);
            
            if (row[i][num] || col[j][num] || box[boxIndex][num]) {
                return false; // duplicate found
            }
            
            row[i][num] = col[j][num] = box[boxIndex][num] = true;
        }
    }
    
    return true;
}
