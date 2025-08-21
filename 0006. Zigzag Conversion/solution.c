#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int n = strlen(s);
    if (numRows == 1 || numRows >= n) {
        // no zigzag needed
        char* res = (char*)malloc((n + 1) * sizeof(char));
        strcpy(res, s);
        return res;
    }

    // allocate space for row strings
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* lens = (int*)calloc(numRows, sizeof(int)); // track length per row

    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((n + 1) * sizeof(char));
        rows[i][0] = '\0';
    }

    int currRow = 0;
    int step = 1; // direction: +1 = down, -1 = up

    for (int i = 0; i < n; i++) {
        rows[currRow][lens[currRow]++] = s[i];
        rows[currRow][lens[currRow]] = '\0';

        if (currRow == 0) step = 1;
        else if (currRow == numRows - 1) step = -1;

        currRow += step;
    }

    // concatenate all rows
    char* res = (char*)malloc((n + 1) * sizeof(char));
    res[0] = '\0';
    for (int i = 0; i < numRows; i++) {
        strcat(res, rows[i]);
        free(rows[i]);
    }

    free(rows);
    free(lens);
    return res;
}
