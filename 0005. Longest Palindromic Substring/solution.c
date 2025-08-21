#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    // Helper lambda (simulate expand around center)
    for (int center = 0; center < 2 * n - 1; center++) {
        int left = center / 2;
        int right = left + center % 2;

        while (left >= 0 && right < n && s[left] == s[right]) {
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                start = left;
                maxLen = currLen;
            }
            left--;
            right++;
        }
    }

    // allocate memory for result substring
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}
