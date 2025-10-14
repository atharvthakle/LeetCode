#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    // Initialize adjacency list
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphSize = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(numCourses * sizeof(int));
    }

    // Initialize in-degree array
    int* indegree = (int*)calloc(numCourses, sizeof(int));

    // Build graph and indegree
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][graphSize[b]++] = a;
        indegree[a]++;
    }

    // Queue for BFS
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    // Add courses with 0 indegree
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }

    // Array to store the order
    int* order = (int*)malloc(numCourses * sizeof(int));
    int count = 0;

    // BFS
    while (front < rear) {
        int course = queue[front++];
        order[count++] = course;

        for (int i = 0; i < graphSize[course]; i++) {
            int next = graph[course][i];
            indegree[next]--;
            if (indegree[next] == 0) queue[rear++] = next;
        }
    }

    // If cycle detected (not all courses processed)
    if (count != numCourses) {
        *returnSize = 0;
        free(order);
        order = (int*)malloc(0);
    } else {
        *returnSize = numCourses;
    }

    // Free memory
    for (int i = 0; i < numCourses; i++) free(graph[i]);
    free(graph);
    free(graphSize);
    free(indegree);
    free(queue);

    return order;
}
