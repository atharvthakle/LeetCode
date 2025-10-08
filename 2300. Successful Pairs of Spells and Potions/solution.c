#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    *returnSize = spellsSize;
    int *result = (int *)malloc(spellsSize * sizeof(int));
    if (!result) return NULL;

    // Step 1: Sort potions
    qsort(potions, potionsSize, sizeof(int), compare);

    // Step 2: For each spell, binary search in potions
    for (int i = 0; i < spellsSize; i++) {
        long long spell = spells[i];
        long long minPotion = (success + spell - 1) / spell; // ceil(success / spell)

        // Binary search for first potion >= minPotion
        int left = 0, right = potionsSize - 1, idx = potionsSize;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (potions[mid] >= minPotion) {
                idx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // All potions from idx to end are successful
        result[i] = potionsSize - idx;
    }

    return result;
}
