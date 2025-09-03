#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    // Special case: overflow
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine sign of result
    int negative = (dividend < 0) ^ (divisor < 0);

    // Work with positive numbers using long long
    long long a = llabs((long long)dividend);
    long long b = llabs((long long)divisor);
    long long quotient = 0;

    while (a >= b) {
        long long temp = b, multiple = 1;
        while ((temp << 1) <= a) {
            temp <<= 1;
            multiple <<= 1;
        }
        a -= temp;
        quotient += multiple;
    }

    return negative ? -quotient : quotient;
}
