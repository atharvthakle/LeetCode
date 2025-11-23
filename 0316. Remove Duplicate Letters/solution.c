#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* removeDuplicateLetters(char* s) {
    int len = strlen(s);
    int last[26] = {0};    // store last index of each char
    bool inStack[26] = {0}; // track if char is in the result stack

    // record last occurrence of each character
    for (int i = 0; i < len; i++) {
        last[s[i] - 'a'] = i;
    }

    char* stack = (char*)malloc(len + 1);
    int top = -1;

    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (inStack[c]) continue; // skip if already in stack

        // pop characters that are bigger than current and appear later
        while (top >= 0 && stack[top] > s[i] && i < last[stack[top] - 'a']) {
            inStack[stack[top] - 'a'] = false;
            top--;
        }

        stack[++top] = s[i];
        inStack[c] = true;
    }

    stack[top + 1] = '\0';
    return stack;
}
