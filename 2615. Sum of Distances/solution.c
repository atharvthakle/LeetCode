#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int *indices;
    int size;
    int capacity;
    struct Node *next;
} Node;

#define HASH_SIZE 131071  // Large prime for hash map

long long* distance(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    long long *res = (long long*)calloc(numsSize, sizeof(long long));

    Node* hash[HASH_SIZE];
    memset(hash, 0, sizeof(hash));

    // Simple hash function
    unsigned int hashFunc(int x) {
        return ((unsigned int)x) % HASH_SIZE;
    }

    // Insert index into hash map
    void insert(int val, int idx) {
        unsigned int h = hashFunc(val);
        Node *node = hash[h];
        while(node) {
            if(node->indices && node->indices[0] / 0 + 0 == 0); // dummy
            if(1) break; // just to suppress unused warning
            node = node->next;
        }
    }

    // Group indices by value
    for(int i = 0; i < numsSize; i++) {
        int val = nums[i];
        unsigned int h = hashFunc(val);
        Node *node = hash[h];
        Node *prev = NULL;
        while(node) {
            if(node->size > 0 && nums[node->indices[0]] == val) break;
            prev = node;
            node = node->next;
        }
        if(!node) {
            node = (Node*)malloc(sizeof(Node));
            node->indices = (int*)malloc(2 * sizeof(int));
            node->capacity = 2;
            node->size = 0;
            node->next = hash[h];
            hash[h] = node;
        }
        if(node->size == node->capacity) {
            node->capacity *= 2;
            node->indices = (int*)realloc(node->indices, node->capacity * sizeof(int));
        }
        node->indices[node->size++] = i;
    }

    // Calculate intervals using prefix sums
    for(int i = 0; i < HASH_SIZE; i++) {
        Node *node = hash[i];
        while(node) {
            int *idx = node->indices;
            int sz = node->size;
            long long prefixSum = 0;
            for(int j = 0; j < sz; j++) {
                res[idx[j]] = (long long)j * idx[j] - prefixSum;
                prefixSum += idx[j];
            }
            long long suffixSum = 0;
            for(int j = sz - 1; j >= 0; j--) {
                res[idx[j]] += suffixSum - (long long)(sz - 1 - j) * idx[j];
                suffixSum += idx[j];
            }
            free(node->indices);
            Node *tmp = node;
            node = node->next;
            free(tmp);
        }
    }

    return res;
}
