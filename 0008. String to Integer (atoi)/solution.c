#include <limits.h>

int myAtoi(char *s) {
    int i = 0;
    long result = 0;
    int sign = 1;

    // Skip leading whitespaces
    while (s[i] == ' ') i++;

    // Check sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') sign = -1;
        i++;
    }

    // Convert digits with overflow check
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        // Check overflow BEFORE multiplying by 10
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return (int)(sign * result);
}
