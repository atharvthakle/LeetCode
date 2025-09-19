#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int rows;
    int** grid; // rows x 26
} Spreadsheet;

// Helper: convert cell reference like "B2" -> value
int getCellValue(Spreadsheet* obj, const char* cell) {
    if (isdigit(cell[0])) {
        // direct integer
        return atoi(cell);
    }
    int col = cell[0] - 'A';
    int row = atoi(cell + 1) - 1; // 1-indexed to 0-indexed
    if (row < 0 || row >= obj->rows || col < 0 || col >= 26) return 0;
    return obj->grid[row][col];
}

Spreadsheet* spreadsheetCreate(int rows) {
    Spreadsheet* obj = (Spreadsheet*)malloc(sizeof(Spreadsheet));
    obj->rows = rows;
    obj->grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        obj->grid[i] = (int*)calloc(26, sizeof(int)); // init all to 0
    }
    return obj;
}

void spreadsheetSetCell(Spreadsheet* obj, char* cell, int value) {
    int col = cell[0] - 'A';
    int row = atoi(cell + 1) - 1;
    if (row >= 0 && row < obj->rows && col >= 0 && col < 26) {
        obj->grid[row][col] = value;
    }
}

void spreadsheetResetCell(Spreadsheet* obj, char* cell) {
    int col = cell[0] - 'A';
    int row = atoi(cell + 1) - 1;
    if (row >= 0 && row < obj->rows && col >= 0 && col < 26) {
        obj->grid[row][col] = 0;
    }
}

int spreadsheetGetValue(Spreadsheet* obj, char* formula) {
    // Formula always looks like "=X+Y"
    char* expr = formula + 1; // skip '='
    char* plus = strchr(expr, '+');
    if (!plus) return 0;

    *plus = '\0'; // split into two parts
    char* left = expr;
    char* right = plus + 1;

    int val1 = getCellValue(obj, left);
    int val2 = getCellValue(obj, right);

    *plus = '+'; // restore string
    return val1 + val2;
}

void spreadsheetFree(Spreadsheet* obj) {
    for (int i = 0; i < obj->rows; i++) {
        free(obj->grid[i]);
    }
    free(obj->grid);
    free(obj);
}

/**
 * Your Spreadsheet struct will be instantiated and called as such:
 * Spreadsheet* obj = spreadsheetCreate(rows);
 * spreadsheetSetCell(obj, cell, value);
 * spreadsheetResetCell(obj, cell);
 * int param_3 = spreadsheetGetValue(obj, formula);
 * spreadsheetFree(obj);
 */
