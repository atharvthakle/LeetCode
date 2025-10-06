#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX

typedef struct {
    int r, c, effort;
} Cell;

typedef struct {
    Cell* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (Cell*)malloc(sizeof(Cell) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(Cell* a, Cell* b) {
    Cell temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, int r, int c, int effort) {
    Cell newCell = {r, c, effort};
    heap->data[heap->size++] = newCell;
    int i = heap->size - 1;
    while (i > 0 && heap->data[i].effort < heap->data[(i - 1) / 2].effort) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Cell pop(MinHeap* heap) {
    Cell root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int i = 0;

    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap->size && heap->data[left].effort < heap->data[smallest].effort)
            smallest = left;
        if (right < heap->size && heap->data[right].effort < heap->data[smallest].effort)
            smallest = right;

        if (smallest == i)
            break;
        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }
    return root;
}

bool isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize) {
    int rows = heightsSize;
    int cols = heightsColSize[0];
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    int** effort = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        effort[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
            effort[i][j] = INF;
    }

    MinHeap* heap = createHeap(rows * cols);
    push(heap, 0, 0, 0);
    effort[0][0] = 0;

    while (!isEmpty(heap)) {
        Cell cell = pop(heap);
        int r = cell.r, c = cell.c, currEffort = cell.effort;

        if (r == rows - 1 && c == cols - 1)
            return currEffort;

        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                int diff = abs(heights[nr][nc] - heights[r][c]);
                int newEffort = currEffort > diff ? currEffort : diff;
                if (newEffort < effort[nr][nc]) {
                    effort[nr][nc] = newEffort;
                    push(heap, nr, nc, newEffort);
                }
            }
        }
    }
    return -1;
}
