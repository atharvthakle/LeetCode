/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

#include <stdlib.h>

struct Node* copyRandomList(struct Node* head) {
    if (!head) return NULL;

    struct Node* curr = head;

    // Step 1: Clone each node and insert right after original
    while (curr) {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = curr->val;
        copy->random = NULL;
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    // Step 2: Assign random pointers to the copied nodes
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Step 3: Separate the original list and the copied list
    curr = head;
    struct Node* newHead = head->next;
    while (curr) {
        struct Node* copy = curr->next;
        curr->next = copy->next;
        if (copy->next) {
            copy->next = copy->next->next;
        }
        curr = curr->next;
    }

    return newHead;
}
