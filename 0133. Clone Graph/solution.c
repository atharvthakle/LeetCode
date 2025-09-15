#include <stdlib.h>

struct Node* cloneGraph(struct Node* s) {
    if (!s) return NULL;

    // A simple array (1–100) to store cloned nodes, initialized to NULL
    struct Node* map[101] = {NULL};

    // DFS helper
    struct Node* dfs(struct Node* node) {
        if (!node) return NULL;

        // If already cloned, return it
        if (map[node->val]) return map[node->val];

        // Create a new node
        struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
        clone->val = node->val;
        clone->numNeighbors = node->numNeighbors;
        clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

        // Save in map before recursion (to handle cycles)
        map[node->val] = clone;

        // Recursively clone neighbors
        for (int i = 0; i < node->numNeighbors; i++) {
            clone->neighbors[i] = dfs(node->neighbors[i]);
        }

        return clone;
    }

    return dfs(s);
}
