#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator for sorting
int compare(const void* a, const void* b) {
    char ab[22], ba[22];
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    return strcmp(ba, ab); // descending order
}

char* largestNumber(int* nums, int numsSize) {
    // Sort numbers using custom comparator
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Allocate large buffer for result
    char* result = (char*)malloc(numsSize * 11 + 1); 
    result[0] = '\0';
    
    // Concatenate sorted numbers
    for (int i = 0; i < numsSize; i++) {
        char buffer[12];
        sprintf(buffer, "%d", nums[i]);
        strcat(result, buffer);
    }
    
    // Edge case: if the result starts with '0', then it's all zeros
    if (result[0] == '0') {
        result[1] = '\0';
    }
    
    return result;
}
