#include <stdlib.h>

#define HASH_SIZE 100003 // a large prime for hash table

typedef struct Node {
    int key;   // prefix sum
    int value; // count of occurrences
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

void insertOrIncrement(int key) {
    Node* node = find(key);
    if (node) {
        node->value += 1;
    } else {
        int h = hashFunc(key);
        node = (Node*)malloc(sizeof(Node));
        node->key = key;
        node->value = 1;
        node->next = hash[h];
        hash[h] = node;
    }
}

int getCount(int key) {
    Node* node = find(key);
    return node ? node->value : 0;
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

int subarraySum(int* nums, int numsSize, int k) {
    for (int i = 0; i < HASH_SIZE; i++) hash[i] = NULL;

    insertOrIncrement(0); // prefix sum 0 occurs once
    int sum = 0;
    int result = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        result += getCount(sum - k); // check if (sum - k) exists
        insertOrIncrement(sum);
    }

    freeHash();
    return result;
}
