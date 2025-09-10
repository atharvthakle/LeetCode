struct Node* connect(struct Node* root) {
    if (root == NULL)
        return NULL;

    struct Node* leftmost = root;

    while (leftmost->left != NULL) {  // while there’s another level
        struct Node* head = leftmost;
        while (head != NULL) {
            // Connect children
            head->left->next = head->right;

            // Connect across parents
            if (head->next != NULL)
                head->right->next = head->next->left;

            head = head->next;
        }
        leftmost = leftmost->left; // move down a level
    }

    return root;
}
