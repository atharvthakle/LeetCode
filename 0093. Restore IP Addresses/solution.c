#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValidSegment(const char* s, int start, int end) {
    int len = end - start + 1;
    if (len > 3 || len <= 0) return false;
    if (len > 1 && s[start] == '0') return false; // leading zero
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
        num = num * 10 + (s[i] - '0');
    }
    return num <= 255;
}

void backtrack(char* s, int s_len, int start, int segment, char* path, int path_len, char*** result, int* returnSize) {
    if (segment == 4 && start == s_len) {
        path[path_len - 1] = '\0'; // replace last dot with null terminator
        (*result)[*returnSize] = strdup(path);
        (*returnSize)++;
        return;
    }
    if (segment >= 4) return;

    for (int len = 1; len <= 3; len++) {
        if (start + len - 1 >= s_len) break;
        if (!isValidSegment(s, start, start + len - 1)) continue;

        // append segment to path
        for (int i = 0; i < len; i++)
            path[path_len + i] = s[start + i];
        path[path_len + len] = '.';

        backtrack(s, s_len, start + len, segment + 1, path, path_len + len + 1, result, returnSize);
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    int s_len = strlen(s);
    *returnSize = 0;
    if (s_len < 4 || s_len > 12) return NULL;

    char** result = malloc(sizeof(char*) * 1000); // max possible addresses
    char* path = malloc(sizeof(char) * 16); // "255.255.255.255" + null
    backtrack(s, s_len, 0, 0, path, 0, &result, returnSize);
    free(path);
    return result;
}
