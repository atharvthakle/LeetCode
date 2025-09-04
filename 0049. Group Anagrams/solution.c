#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper: compare for qsort
int cmpChar(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

// Helper: create sorted signature of a string
char* getSignature(const char* str) {
    int len = strlen(str);
    char* sig = (char*)malloc((len + 1) * sizeof(char));
    strcpy(sig, str);
    qsort(sig, len, sizeof(char), cmpChar);
    return sig;
}

typedef struct {
    char* key;        // signature
    char** words;     // group of anagrams
    int size;         // number of words
    int capacity;     // capacity
} Group;

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (strsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    Group* groups = (Group*)malloc(strsSize * sizeof(Group));
    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        char* sig = getSignature(strs[i]);
        int found = -1;

        // check if signature already exists
        for (int g = 0; g < groupCount; g++) {
            if (strcmp(groups[g].key, sig) == 0) {
                found = g;
                break;
            }
        }

        if (found == -1) {
            // create new group
            groups[groupCount].key = sig;
            groups[groupCount].capacity = 4;
            groups[groupCount].size = 0;
            groups[groupCount].words = (char**)malloc(groups[groupCount].capacity * sizeof(char*));
            found = groupCount;
            groupCount++;
        } else {
            free(sig); // already have this signature
        }

        // add word to group
        if (groups[found].size >= groups[found].capacity) {
            groups[found].capacity *= 2;
            groups[found].words = (char**)realloc(groups[found].words, groups[found].capacity * sizeof(char*));
        }
        groups[found].words[groups[found].size++] = strs[i];
    }

    // prepare return values
    char*** result = (char***)malloc(groupCount * sizeof(char**));
    *returnColumnSizes = (int*)malloc(groupCount * sizeof(int));
    for (int g = 0; g < groupCount; g++) {
        result[g] = groups[g].words;
        (*returnColumnSizes)[g] = groups[g].size;
        free(groups[g].key);
    }
    free(groups);

    *returnSize = groupCount;
    return result;
}
