#include <stdio.h>
#include <stdlib.h>

#define MAX_COMBINATIONS 200   // safe upper bound (<150 as per problem)
#define MAX_LENGTH 100         // maximum possible length of any combination

int** results;                // to hold final combinations
int* colSizes;                // sizes of each combination
int returnCount;              // number of combinations found

int* current;                 // current combination being built
int currentSize;              // size of current combination

void backtrack(int* candidates, int candidatesSize, int target, int start) {
    if (target == 0) {
        // Found a valid combination
        results[returnCount] = (int*)malloc(sizeof(int) * currentSize);
        for (int i = 0; i < currentSize; i++) {
            results[returnCount][i] = current[i];
        }
        colSizes[returnCount] = currentSize;
        returnCount++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            // Choose
            current[currentSize++] = candidates[i];
            // Recurse (same i since we can reuse)
            backtrack(candidates, candidatesSize, target - candidates[i], i);
            // Undo (backtrack)
            currentSize--;
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    results = (int**)malloc(sizeof(int*) * MAX_COMBINATIONS);
    colSizes = (int*)malloc(sizeof(int) * MAX_COMBINATIONS);
    current = (int*)malloc(sizeof(int) * MAX_LENGTH);
    currentSize = 0;
    returnCount = 0;

    backtrack(candidates, candidatesSize, target, 0);

    *returnSize = returnCount;
    *returnColumnSizes = colSizes;
    return results;
}
