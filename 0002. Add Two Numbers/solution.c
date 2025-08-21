#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list is already given by the judge:
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;  // dummy head
    struct ListNode* curr = &dummy;
    dummy.next = NULL;
    
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry > 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        
        int sum = x + y + carry;
        carry = sum / 10;
        
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        curr->next = newNode;
        curr = curr->next;
        
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    
    return dummy.next;
}
