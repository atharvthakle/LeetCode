#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function for backtracking
void backtrack(char **result, int *returnSize, char *current, int open, int close, int n) {
    if (strlen(current) == 2 * n) {
        // store a copy of the current string
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        int len = strlen(current);
        current[len] = '(';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open + 1, close, n);
        current[len] = '\0'; // backtrack
    }

    if (close < open) {
        int len = strlen(current);
        current[len] = ')';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open, close + 1, n);
        current[len] = '\0'; // backtrack
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    // Max number of results is the nth Catalan number.
    // For n=8 it's 1430, safe to allocate larger (5000).
    char **result = (char**)malloc(sizeof(char*) * 5000);
    *returnSize = 0;

    // buffer for building strings
    char *current = (char*)malloc(sizeof(char) * (2 * n + 1));
    current[0] = '\0';

    backtrack(result, returnSize, current, 0, 0, n);

    free(current);
    return result;
}

// --- For local testing ---
// int main() {
//     int returnSize;
//     char **res = generateParenthesis(3, &returnSize);
//     for (int i = 0; i < returnSize; i++) {
//         printf("%s\n", res[i]);
//         free(res[i]); // free each string
//     }
//     free(res); // free array of pointers
//     return 0;
// }
