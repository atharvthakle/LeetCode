# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Dummy node to handle head changes
        dummy = ListNode(0)
        dummy.next = head
        prev_group = dummy

        while True:
            # Check if there are at least k nodes left
            kth = prev_group
            for _ in range(k):
                kth = kth.next
                if not kth:
                    return dummy.next

            # Reverse k nodes
            group_next = kth.next
            prev, curr = kth.next, prev_group.next
            for _ in range(k):
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp

            # Connect previous group to reversed group
            tmp = prev_group.next
            prev_group.next = prev
            prev_group = tmp
