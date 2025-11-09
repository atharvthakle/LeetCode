#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int hIndex(int* citations, int citationsSize) {
    // Sort citations in ascending order
    qsort(citations, citationsSize, sizeof(int), compare);
    
    int h = 0;
    for (int i = 0; i < citationsSize; i++) {
        int papers = citationsSize - i; // number of papers with >= citations[i] citations
        if (citations[i] >= papers) {
            h = papers;
            break;
        }
    }
    
    return h;
}
