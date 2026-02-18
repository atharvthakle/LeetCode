public class Solution {
    public Node Flatten(Node head) {
        if (head == null) return head;
        FlattenDFS(head);
        return head;
    }

    // Returns the tail of the flattened list starting at 'node'
    private Node FlattenDFS(Node node) {
        Node curr = node;
        Node last = null;

        while (curr != null) {
            Node next = curr.next;

            // If there is a child, flatten it
            if (curr.child != null) {
                Node childHead = curr.child;
                Node childTail = FlattenDFS(childHead);

                // Connect current node to child head
                curr.next = childHead;
                childHead.prev = curr;
                curr.child = null;

                // If there was a next node, connect child tail to it
                if (next != null) {
                    childTail.next = next;
                    next.prev = childTail;
                }

                last = childTail;
                curr = childTail; // continue from tail
            } else {
                last = curr;
            }

            curr = curr.next;
        }

        return last;
    }
}
