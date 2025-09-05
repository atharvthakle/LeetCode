#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    int len = strlen(path);

    // Allocate memory for stack (array of strings)
    char** stack = (char**)malloc(len * sizeof(char*));
    int top = 0;

    // Tokenize path by '/'
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, ".") == 0) {
            // Ignore "."
        } else if (strcmp(token, "..") == 0) {
            // Pop if stack not empty
            if (top > 0) {
                free(stack[--top]);
            }
        } else if (strlen(token) > 0) {
            // Push valid directory
            stack[top] = (char*)malloc(strlen(token) + 1);
            strcpy(stack[top], token);
            top++;
        }
        token = strtok(NULL, "/");
    }

    // Construct canonical path
    if (top == 0) {
        char* res = (char*)malloc(2);
        strcpy(res, "/");
        free(stack);
        return res;
    }

    // Calculate total length
    int totalLen = 0;
    for (int i = 0; i < top; i++) {
        totalLen += strlen(stack[i]) + 1; // +1 for '/'
    }

    char* res = (char*)malloc(totalLen + 1);
    res[0] = '\0';

    for (int i = 0; i < top; i++) {
        strcat(res, "/");
        strcat(res, stack[i]);
        free(stack[i]); // Free memory
    }

    free(stack);
    return res;
}
