# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import heapq

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # Min-heap for (node value, index of list, node reference)
        heap = []
        
        # Initialize the heap with the head node of each list
        for i, l in enumerate(lists):
            if l:
                heapq.heappush(heap, (l.val, i, l))
        
        # Dummy head to build the result
        dummy = ListNode(0)
        curr = dummy
        
        while heap:
            val, i, node = heapq.heappop(heap)   # Pop smallest node
            curr.next = node                     # Add it to result list
            curr = curr.next
            if node.next:                        # Push next node of same list
                heapq.heappush(heap, (node.next.val, i, node.next))
        
        return dummy.next
