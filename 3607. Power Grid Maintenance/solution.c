#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ---------- DSU (Union-Find) ----------
int find(int *parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSets(int *parent, int *rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a == b) return;
    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[a] > rank[b]) parent[b] = a;
    else {
        parent[b] = a;
        rank[a]++;
    }
}

// ---------- Min-Heap for online stations ----------
typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int cap) {
    MinHeap *h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (int*)malloc(cap * sizeof(int));
    h->size = 0;
    h->capacity = cap > 0 ? cap : 1;
    return h;
}

void heapPush(MinHeap *h, int val) {
    // Auto-expand when full
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (int*)realloc(h->data, h->capacity * sizeof(int));
        if (!h->data) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    int i = h->size++;
    h->data[i] = val;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p] <= h->data[i]) break;
        int t = h->data[p];
        h->data[p] = h->data[i];
        h->data[i] = t;
        i = p;
    }
}

int heapPop(MinHeap *h) {
    if (h->size == 0) return -1;
    int res = h->data[0];
    h->size--;
    if (h->size > 0) {
        h->data[0] = h->data[h->size];
        int i = 0;
        while (1) {
            int l = 2 * i + 1, r = 2 * i + 2, s = i;
            if (l < h->size && h->data[l] < h->data[s]) s = l;
            if (r < h->size && h->data[r] < h->data[s]) s = r;
            if (s == i) break;
            int t = h->data[i];
            h->data[i] = h->data[s];
            h->data[s] = t;
            i = s;
        }
    }
    return res;
}

int heapTop(MinHeap *h) {
    return (h->size == 0) ? -1 : h->data[0];
}

// ---------- Main Function ----------
int* processQueries(int c, int** connections, int connectionsSize, int* connectionsColSize,
                    int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int *parent = (int*)malloc((c + 1) * sizeof(int));
    int *rank = (int*)calloc((c + 1), sizeof(int));
    int *online = (int*)malloc((c + 1) * sizeof(int));
    MinHeap **heaps = (MinHeap**)malloc((c + 1) * sizeof(MinHeap*));

    for (int i = 1; i <= c; i++) {
        parent[i] = i;
        online[i] = 1;
        heaps[i] = NULL;
    }

    // Build DSU
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        unionSets(parent, rank, u, v);
    }

    // Initialize heaps for each component
    for (int i = 1; i <= c; i++) {
        int root = find(parent, i);
        if (heaps[root] == NULL) {
            heaps[root] = createHeap(8);
        }
        heapPush(heaps[root], i);
    }

    int *result = (int*)malloc(queriesSize * sizeof(int));
    int resCount = 0;

    // Process queries
    for (int i = 0; i < queriesSize; i++) {
        int type = queries[i][0];
        int x = queries[i][1];
        int p = find(parent, x);

        if (type == 1) {  // Maintenance check
            if (online[x]) {
                result[resCount++] = x;
            } else {
                int minOnline = -1;
                while (heaps[p]->size > 0) {
                    int top = heapTop(heaps[p]);
                    if (top != -1 && online[top]) {
                        minOnline = top;
                        break;
                    } else {
                        heapPop(heaps[p]);
                    }
                }
                result[resCount++] = minOnline;
            }
        } else if (type == 2) {  // Go offline
            online[x] = 0;
        }
    }

    *returnSize = resCount;
    return result;
}
