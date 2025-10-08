#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int* stack;
    int* minStack;
    int size;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 1000; // initial capacity
    obj->stack = (int*)malloc(obj->capacity * sizeof(int));
    obj->minStack = (int*)malloc(obj->capacity * sizeof(int));
    obj->size = 0;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->size >= obj->capacity) { // resize if needed
        obj->capacity *= 2;
        obj->stack = (int*)realloc(obj->stack, obj->capacity * sizeof(int));
        obj->minStack = (int*)realloc(obj->minStack, obj->capacity * sizeof(int));
    }

    obj->stack[obj->size] = val;
    if (obj->size == 0)
        obj->minStack[obj->size] = val;
    else
        obj->minStack[obj->size] = val < obj->minStack[obj->size - 1] ? val : obj->minStack[obj->size - 1];

    obj->size++;
}

void minStackPop(MinStack* obj) {
    if (obj->size > 0)
        obj->size--;
}

int minStackTop(MinStack* obj) {
    if (obj->size == 0) return INT_MIN; // or handle error
    return obj->stack[obj->size - 1];
}

int minStackGetMin(MinStack* obj) {
    if (obj->size == 0) return INT_MIN; // or handle error
    return obj->minStack[obj->size - 1];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}
