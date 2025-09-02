#include <stdbool.h>
#include <stdlib.h>

#define HASH_SIZE 100003 // a large prime for hash table

typedef struct Node {
    int key;   // modulo value
    int value; // first index
    struct Node* next;
} Node;

Node* hash[HASH_SIZE];

int hashFunc(int key) {
    if (key < 0) key = -key;
    return key % HASH_SIZE;
}

Node* find(int key) {
    int h = hashFunc(key);
    Node* curr = hash[h];
    while (curr) {
        if (curr->key == key) return curr;
        curr = curr->next;
    }
    return NULL;
}

void insert(int key, int value) {
    int h = hashFunc(key);
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = hash[h];
    hash[h] = node;
}

void freeHash() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = hash[i];
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
        hash[i] = NULL;
    }
}

bool checkSubarraySum(int* nums, int numsSize, int k) {
    if (numsSize < 2) return false;

    for (int i = 0; i < HASH_SIZE; i++) hash[i] = NULL;

    insert(0, -1); // handle subarrays starting at index 0

    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        int mod = sum % k;
        if (mod < 0) mod += k;

        Node* node = find(mod);
        if (node) {
            if (i - node->value >= 2) {
                freeHash();
                return true;
            }
        } else {
            insert(mod, i);
        }
    }

    freeHash();
    return false;
}
