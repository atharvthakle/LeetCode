#include <stdbool.h>
#include <string.h>

bool doesAliceWin(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;  // Alice can make the first move
        }
    }
    return false;  // No vowels, Alice loses immediately
}
