#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* seq;
    int count;
    struct Node* next;
} Node;

#define HASH_SIZE 100003  // A prime number for hash table size

unsigned long hash(char* str) {
    unsigned long h = 5381;
    for (int i = 0; i < 10; i++) {
        h = ((h << 5) + h) + str[i]; // h * 33 + c
    }
    return h % HASH_SIZE;
}

char** findRepeatedDnaSequences(char* s, int* returnSize) {
    *returnSize = 0;
    int len = strlen(s);
    if (len < 10) return NULL;

    Node* hashTable[HASH_SIZE];
    memset(hashTable, 0, sizeof(hashTable));

    char** result = (char**)malloc(sizeof(char*) * (len - 9));

    for (int i = 0; i <= len - 10; i++) {
        char sub[11];
        strncpy(sub, s + i, 10);
        sub[10] = '\0';

        unsigned long h = hash(sub);
        Node* node = hashTable[h];
        int found = 0;

        while (node) {
            if (strcmp(node->seq, sub) == 0) {
                node->count++;
                if (node->count == 2) { // add only once
                    result[*returnSize] = strdup(sub);
                    (*returnSize)++;
                }
                found = 1;
                break;
            }
            node = node->next;
        }

        if (!found) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->seq = strdup(sub);
            newNode->count = 1;
            newNode->next = hashTable[h];
            hashTable[h] = newNode;
        }
    }

    // free hash table nodes
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* node = hashTable[i];
        while (node) {
            Node* tmp = node;
            node = node->next;
            free(tmp->seq);
            free(tmp);
        }
    }

    return result;
}
