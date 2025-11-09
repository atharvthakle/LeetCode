#include <stdio.h>

int hIndex(int* citations, int citationsSize) {
    int left = 0, right = citationsSize - 1;
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int papers = citationsSize - mid; // number of papers with ≥ citations[mid] citations
        
        if (citations[mid] >= papers) {
            // citations[mid] is enough for at least 'papers' papers
            result = papers;
            right = mid - 1; // try to find smaller index (maybe higher h)
        } else {
            left = mid + 1; // need more citations
        }
    }
    
    return result;
}
