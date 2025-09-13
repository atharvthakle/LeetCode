#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Function to count bits in an integer
static inline int bitCount(int x) {
    int count = 0;
    while (x) {
        x &= (x - 1);
        count++;
    }
    return count;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* canMakePaliQueries(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int n = strlen(s);
    *returnSize = queriesSize;
    bool* ans = (bool*)malloc(sizeof(bool) * queriesSize);

    // prefix[i] = parity mask of s[0..i-1]
    int* prefix = (int*)malloc(sizeof(int) * (n + 1));
    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        int bit = 1 << (s[i] - 'a');
        prefix[i + 1] = prefix[i] ^ bit;
    }

    for (int q = 0; q < queriesSize; q++) {
        int l = queries[q][0];
        int r = queries[q][1];
        int k = queries[q][2];

        int mask = prefix[r + 1] ^ prefix[l];
        int oddCount = bitCount(mask);

        // Need at most oddCount/2 replacements
        ans[q] = (oddCount / 2) <= k;
    }

    free(prefix);
    return ans;
}
