#include <stdlib.h>
#include <string.h>

const char* mapping[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void backtrack(char* digits, int index, char* current, char** result, int* returnSize) {
    if (digits[index] == '\0') {  
        // reached end of digits, store current combination
        result[*returnSize] = strdup(current);  
        (*returnSize)++;
        return;
    }

    const char* letters = mapping[digits[index] - '0'];
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if (digits == NULL || *digits == '\0') {
        return NULL;
    }

    // max combinations: 4^4 = 256 (since digits length ≤ 4, and '7'/'9' map to 4 letters)
    char** result = (char**)malloc(256 * sizeof(char*));
    char current[5];  // max length = 4 digits, +1 for '\0'
    current[strlen(digits)] = '\0';

    backtrack(digits, 0, current, result, returnSize);

    return result;
}
