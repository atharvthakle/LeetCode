#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int calculate(char* s) {
    long long num = 0;
    char op = '+';
    long long stack[300000];
    int top = -1;

    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        // If we encounter an operator or end of string
        if ((!isdigit(s[i]) && s[i] != ' ') || s[i + 1] == '\0') {
            if (op == '+') {
                stack[++top] = num;
            } else if (op == '-') {
                stack[++top] = -num;
            } else if (op == '*') {
                stack[top] = stack[top] * num;
            } else if (op == '/') {
                // Truncate toward zero (C default for integer division)
                stack[top] = stack[top] / num;
            }
            op = s[i];
            num = 0;
        }
    }

    long long result = 0;
    for (int i = 0; i <= top; i++)
        result += stack[i];

    return (int)result;
}
