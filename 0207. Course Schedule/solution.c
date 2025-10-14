#include <stdlib.h>
#include <stdbool.h>

// Queue implementation for BFS
typedef struct {
    int* data;
    int front;
    int rear;
} Queue;

Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * n);
    q->front = q->rear = 0;
    return q;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    if (numCourses == 0) return true;

    // Step 1: Build adjacency list and indegree array
    int** adj = (int**)malloc(sizeof(int*) * numCourses);
    int* adjSize = (int*)calloc(numCourses, sizeof(int));
    int* indegree = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(sizeof(int) * numCourses);  // upper bound
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;  // edge b -> a (must take b before a)
        indegree[a]++;
    }

    // Step 2: Initialize queue with courses having 0 indegree
    Queue* q = createQueue(numCourses);
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) enqueue(q, i);
    }

    // Step 3: BFS (Kahn's Algorithm)
    int count = 0;
    while (!isEmpty(q)) {
        int course = dequeue(q);
        count++;

        for (int i = 0; i < adjSize[course]; i++) {
            int next = adj[course][i];
            indegree[next]--;
            if (indegree[next] == 0) enqueue(q, next);
        }
    }

    // Step 4: Check if all courses can be completed
    bool canFinishAll = (count == numCourses);

    // Free memory
    for (int i = 0; i < numCourses; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSize);
    free(indegree);
    freeQueue(q);

    return canFinishAll;
}
