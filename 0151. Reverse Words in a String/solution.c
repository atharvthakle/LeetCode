#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void reverse(char* s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

char* reverseWords(char* s) {
    int n = strlen(s);
    char* temp = (char*)malloc(n + 1);
    int j = 0;
    int i = 0;
    
    // Step 1: Remove leading/trailing/multiple spaces
    while (i < n) {
        while (i < n && s[i] == ' ') i++;          // skip spaces
        while (i < n && s[i] != ' ') temp[j++] = s[i++]; // copy word
        while (i < n && s[i] == ' ') i++;          // skip spaces after word
        if (i < n) temp[j++] = ' ';                // add single space if more words
    }
    temp[j] = '\0';
    
    // Step 2: Reverse the entire cleaned string
    reverse(temp, 0, j - 1);
    
    // Step 3: Reverse each word individually
    int start = 0;
    for (i = 0; i <= j; i++) {
        if (temp[i] == ' ' || temp[i] == '\0') {
            reverse(temp, start, i - 1);
            start = i + 1;
        }
    }
    
    return temp;
}
