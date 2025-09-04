#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int capacity = intervalsSize + 1; // worst case, one more interval
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

    int idx = 0;
    int i = 0;

    // Case 1: intervals before newInterval
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[idx] = (int*)malloc(sizeof(int) * 2);
        result[idx][0] = intervals[i][0];
        result[idx][1] = intervals[i][1];
        (*returnColumnSizes)[idx] = 2;
        idx++;
        i++;
    }

    // Case 2: overlapping intervals
    int start = newInterval[0];
    int end = newInterval[1];
    while (i < intervalsSize && intervals[i][0] <= end) {
        if (intervals[i][0] < start) start = intervals[i][0];
        if (intervals[i][1] > end) end = intervals[i][1];
        i++;
    }
    result[idx] = (int*)malloc(sizeof(int) * 2);
    result[idx][0] = start;
    result[idx][1] = end;
    (*returnColumnSizes)[idx] = 2;
    idx++;

    // Case 3: intervals after newInterval
    while (i < intervalsSize) {
        result[idx] = (int*)malloc(sizeof(int) * 2);
        result[idx][0] = intervals[i][0];
        result[idx][1] = intervals[i][1];
        (*returnColumnSizes)[idx] = 2;
        idx++;
        i++;
    }

    *returnSize = idx;
    return result;
}
