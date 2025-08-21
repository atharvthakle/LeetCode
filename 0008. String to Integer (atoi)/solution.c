#include <limits.h>  // for INT_MAX and INT_MIN
#include <ctype.h>   // for isdigit and isspace

int myAtoi(char* s) {
    long result = 0;   // use long for intermediate to detect overflow
    int sign = 1;

    // Step 1: Skip leading whitespaces
    while (*s == ' ') {
        s++;
    }

    // Step 2: Handle sign
    if (*s == '+' || *s == '-') {
        if (*s == '-') sign = -1;
        s++;
    }

    // Step 3: Convert digits
    while (isdigit(*s)) {
        int digit = *s - '0';

        // Step 4: Check for overflow before adding
        if (result > (LONG_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        s++;
    }

    return (int)(sign * result);
}
