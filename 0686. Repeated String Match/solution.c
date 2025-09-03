#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int repeatedStringMatch(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);

    // Max possible repetitions = (lenB / lenA) + 2
    int maxRepeats = lenB / lenA + 2;
    
    // Allocate buffer big enough
    int bufferSize = lenA * maxRepeats + 1;
    char* repeated = (char*)malloc(bufferSize);
    repeated[0] = '\0';

    // Build repeated string step by step
    for (int i = 1; i <= maxRepeats; i++) {
        strcat(repeated, a);
