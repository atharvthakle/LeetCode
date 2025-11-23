#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Helper function to add two numeric strings
char* stringAdd(const char* num1, const char* num2) {
    int len1 = strlen(num1), len2 = strlen(num2);
    int maxLen = (len1 > len2 ? len1 : len2) + 2; // +1 for carry, +1 for '\0'
    char *res = (char*)malloc(maxLen);
    res[maxLen - 1] = '\0';

    int i = len1 - 1, j = len2 - 1, k = maxLen - 2, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = i >= 0 ? num1[i--] - '0' : 0;
        int digit2 = j >= 0 ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        res[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // shift result to start
    char *start = res + k + 1;
    char *finalRes = strdup(start);
    free(res);
    return finalRes;
}

// Recursive check function
bool check(char* num1, char* num2, char* remaining) {
    char* sumStr = stringAdd(num1, num2);
    int sumLen = strlen(sumStr);
    if (strncmp(remaining, sumStr, sumLen) != 0) {
        free(sumStr);
        return false;
    }
    if (sumLen == strlen(remaining)) { // exactly matched
        free(sumStr);
        return true;
    }
    bool result = check(num2, sumStr, remaining + sumLen);
    free(sumStr);
    return result;
}

bool isAdditiveNumber(char* num) {
    int n = strlen(num);
    for (int i = 1; i <= n / 2; i++) {
        if (i > 1 && num[0] == '0') break; // leading zero not allowed
        for (int j = 1; n - i - j >= (i > j ? i : j); j++) {
            if (j > 1 && num[i] == '0') break; // leading zero not allowed
            char* num1 = strndup(num, i);
            char* num2 = strndup(num + i, j);
            if (check(num1, num2, num + i + j)) {
                free(num1);
                free(num2);
                return true;
            }
            free(num1);
            free(num2);
        }
    }
    return false;
}
