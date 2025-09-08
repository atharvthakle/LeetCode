#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10007  // Prime for hash buckets

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
    struct Node* hnext; // for hashmap chaining
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node** hashmap;
} LRUCache;

// Hash function
unsigned int hashKey(int key) {
    return key % HASH_SIZE;
}

// Create a node
Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = node->next = node->hnext = NULL;
    return node;
}

// Insert node right after head (most recent)
void insertHead(LRUCache* obj, Node* node) {
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

// Remove node from DLL
void removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// Move node to head
void moveToHead(LRUCache* obj, Node* node) {
    removeNode(node);
    insertHead(obj, node);
}

// Pop tail (least recent)
Node* popTail(LRUCache* obj) {
    Node* node = obj->tail->prev;
    removeNode(node);
    return node;
}

// Find node in hashmap
Node* findHash(LRUCache* obj, int key) {
    unsigned int h = hashKey(key);
    Node* cur = obj->hashmap[h];
    while (cur) {
        if (cur->key == key) return cur;
        cur = cur->hnext;
    }
    return NULL;
}

// Insert into hashmap
void insertHash(LRUCache* obj, Node* node) {
    unsigned int h = hashKey(node->key);
    node->hnext = obj->hashmap[h];
    obj->hashmap[h] = node;
}

// Remove from hashmap
void removeHash(LRUCache* obj, int key) {
    unsigned int h = hashKey(key);
    Node* cur = obj->hashmap[h];
    Node* prev = NULL;
    while (cur) {
        if (cur->key == key) {
            if (prev) prev->hnext = cur->hnext;
            else obj->hashmap[h] = cur->hnext;
            return;
        }
        prev = cur;
        cur = cur->hnext;
    }
}

// Create LRUCache
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    obj->hashmap = (Node**)calloc(HASH_SIZE, sizeof(Node*));

    // Dummy head & tail
    obj->head = createNode(0, 0);
    obj->tail = createNode(0, 0);
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;

    return obj;
}

// Get value
int lRUCacheGet(LRUCache* obj, int key) {
    Node* node = findHash(obj, key);
    if (!node) return -1;
    moveToHead(obj, node);
    return node->value;
}

// Put key-value
void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* node = findHash(obj, key);

    if (node) {
        node->value = value;
        moveToHead(obj, node);
    } else {
        Node* newNode = createNode(key, value);
        insertHead(obj, newNode);
        insertHash(obj, newNode);
        obj->size++;

        if (obj->size > obj->capacity) {
            Node* tail = popTail(obj);
            removeHash(obj, tail->key);
            free(tail);
            obj->size--;
        }
    }
}

// Free cache
void lRUCacheFree(LRUCache* obj) {
    Node* cur = obj->head;
    while (cur) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(obj->hashmap);
    free(obj);
}
