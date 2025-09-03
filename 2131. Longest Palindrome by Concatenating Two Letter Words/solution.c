#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 676  // 26 * 26 possible pairs of lowercase letters

int longestPalindrome(char** words, int wordsSize) {
    int count[26][26] = {0};
    int result = 0;
    int hasMiddle = 0;

    for (int i = 0; i < wordsSize; i++) {
        int a = words[i][0] - 'a';
        int b = words[i][1] - 'a';

        if (count[b][a] > 0) {
            // Found a reverse pair
            result += 4;
            count[b][a]--;
        } else {
            count[a][b]++;
        }
    }

    // Check if we can place a self-palindrome (like "cc") in the middle
    for (int i = 0; i < 26; i++) {
        if (count[i][i] > 0) {
            hasMiddle = 1;
            break;
        }
    }

    return result + (hasMiddle ? 2 : 0);
}
