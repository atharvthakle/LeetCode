#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Helper function to check if substring s[start..end] exists in wordDict
bool isInDict(char* s, int start, int end, char** wordDict, int wordDictSize) {
    int len = end - start;
    for (int i = 0; i < wordDictSize; i++) {
        if (strlen(wordDict[i]) == len && strncmp(s + start, wordDict[i], len) == 0) {
            return true;
        }
    }
    return false;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);
    bool* dp = (bool*)calloc(n + 1, sizeof(bool));
    dp[0] = true; // empty string is always valid

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && isInDict(s, j, i, wordDict, wordDictSize)) {
                dp[i] = true;
                break;
            }
        }
    }

    bool result = dp[n];
    free(dp);
    return result;
}
