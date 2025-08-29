#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    // Roman numeral mappings
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
                             "X", "IX", "V", "IV", "I"};

    // Allocate buffer large enough (max Roman length for 3999 is 15 chars + '\0')
    char* result = (char*)malloc(20 * sizeof(char));
    result[0] = '\0';  // start with empty string

    int i = 0;
    while (num > 0) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
        i++;
    }

    return result;
}
