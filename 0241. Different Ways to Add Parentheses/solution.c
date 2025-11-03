#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diffWaysToCompute(char* expression, int* returnSize) {
    int len = strlen(expression);
    int *results = (int*)malloc(10000 * sizeof(int));
    int count = 0;

    for (int i = 0; i < len; i++) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*') {
            int leftSize = 0, rightSize = 0;

            // Split into left and right parts recursively
            char left[25], right[25];
            strncpy(left, expression, i);
            left[i] = '\0';
            strcpy(right, expression + i + 1);

            int *leftResults = diffWaysToCompute(left, &leftSize);
            int *rightResults = diffWaysToCompute(right, &rightSize);

            // Combine results based on the operator
            for (int l = 0; l < leftSize; l++) {
                for (int r = 0; r < rightSize; r++) {
                    int val = 0;
                    if (c == '+') val = leftResults[l] + rightResults[r];
                    else if (c == '-') val = leftResults[l] - rightResults[r];
                    else val = leftResults[l] * rightResults[r];
                    results[count++] = val;
                }
            }
            free(leftResults);
            free(rightResults);
        }
    }

    // Base case: no operator found — expression is a single number
    if (count == 0) {
        results[count++] = atoi(expression);
    }

    *returnSize = count;
    return results;
}
