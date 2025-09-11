#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char* sortVowels(char* s) {
    int n = strlen(s);
    char* result = (char*)malloc((n + 1) * sizeof(char));
    strcpy(result, s);

    // Step 1: frequency count of vowels (ASCII range is enough)
    int freq[128] = {0};
    for (int i = 0; i < n; i++) {
        if (isVowel(s[i])) {
            freq[(int)s[i]]++;
        }
    }

    // Step 2: refill vowels in sorted ASCII order
    int idx = 0;
    for (int ascii = 0; ascii < 128; ascii++) {
        while (freq[ascii] > 0) {
            // move idx forward to find next vowel position
            while (idx < n && !isVowel(result[idx])) {
                idx++;
            }
            if (idx < n) {
                result[idx++] = (char)ascii;
            }
            freq[ascii]--;
        }
    }

    result[n] = '\0';
    return result;
}
