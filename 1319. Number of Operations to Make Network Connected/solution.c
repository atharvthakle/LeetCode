#include <stdlib.h>

int find(int* parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]); // path compression
    }
    return parent[x];
}

void unite(int* parent, int* rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    if (connectionsSize < n - 1) return -1; // not enough cables

    int* parent = (int*)malloc(sizeof(int) * n);
    int* rank = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 0; i < connectionsSize; i++) {
        int a = connections[i][0];
        int b = connections[i][1];
        unite(parent, rank, a, b);
    }

    int components = 0;
    for (int i = 0; i < n; i++) {
        if (find(parent, i) == i) components++;
    }

    free(parent);
    free(rank);

    return components - 1;
}
