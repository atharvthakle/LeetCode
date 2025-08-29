#include <stdbool.h>
#include <string.h>

bool canBeValid(char* s, char* locked) {
    int n = strlen(s);
    if (n % 2 == 1) return false; // odd length cannot be valid

    int balance = 0;

    // Pass 1: left to right (treat unlocked as '(' if needed)
    for (int i = 0; i < n; i++) {
        if (locked[i] == '0' || s[i] == '(') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) return false;
    }

    balance = 0;
    // Pass 2: right to left (treat unlocked as ')' if needed)
    for (int i = n - 1; i >= 0; i--) {
        if (locked[i] == '0' || s[i] == ')') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) return false;
    }

    return true;
}
