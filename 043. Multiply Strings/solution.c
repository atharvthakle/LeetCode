#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        char* res = (char*)malloc(2);
        strcpy(res, "0");
        return res;
    }

    int m = strlen(num1), n = strlen(num2);
    int* prod = (int*)calloc(m + n, sizeof(int));

    // Multiply digit by digit
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + prod[i + j + 1];
            prod[i + j + 1] = sum % 10;
            prod[i + j] += sum / 10;
        }
    }

    // Convert to string
    int k = 0;
    while (k < m + n && prod[k] == 0) k++;  // skip leading zeros

    int len = m + n - k;
    char* res = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        res[i] = prod[k + i] + '0';
    }
    res[len] = '\0';

    free(prod);
    return res;
}
