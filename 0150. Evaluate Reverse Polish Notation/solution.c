#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize]; // max stack size = number of tokens
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char *token = tokens[i];

        // If token is an operator
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {

            int b = stack[top--]; // pop operand2
            int a = stack[top--]; // pop operand1
            int result = 0;

            if (strcmp(token, "+") == 0) result = a + b;
            else if (strcmp(token, "-") == 0) result = a - b;
            else if (strcmp(token, "*") == 0) result = a * b;
            else if (strcmp(token, "/") == 0) result = a / b; // truncates toward 0 automatically in C

            stack[++top] = result; // push result back
        } else {
            // Otherwise, it's a number
            stack[++top] = atoi(token);
        }
    }

    return stack[top]; // final result
}
