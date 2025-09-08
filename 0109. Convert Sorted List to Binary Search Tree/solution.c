/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

// Helper function to create a new tree node
struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to find middle node of linked list
struct ListNode* findMiddle(struct ListNode* head, struct ListNode** prev) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    *prev = NULL;

    while (fast && fast->next) {
        *prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head) return NULL;

    struct ListNode* prev = NULL;
    struct ListNode* mid = findMiddle(head, &prev);

    struct TreeNode* root = newTreeNode(mid->val);

    // base case when only one element
    if (head == mid) return root;

    // disconnect left half from mid
    if (prev) prev->next = NULL;

    // recursively build left & right
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return root;
}
