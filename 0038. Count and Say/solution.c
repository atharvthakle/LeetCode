#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    // Max length is safe under 5000 chars for n <= 30
    char *curr = (char*)malloc(5000);
    char *next = (char*)malloc(5000);
    strcpy(curr, "1");

    for (int step = 2; step <= n; step++) {
        int len = strlen(curr);
        int idx = 0;
        for (int i = 0; i < len; ) {
            char ch = curr[i];
            int count = 0;
            while (i < len && curr[i] == ch) {
                count++;
                i++;
            }
            idx += sprintf(next + idx, "%d%c", count, ch);
        }
        strcpy(curr, next);
    }

    free(next);
    return curr;  // caller is responsible for freeing
}
