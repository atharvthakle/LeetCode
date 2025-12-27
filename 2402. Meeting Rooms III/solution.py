import heapq
from typing import List

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        # Sort meetings by start time
        meetings.sort()
        
        # Min-heap of available rooms
        available = list(range(n))
        heapq.heapify(available)
        
        # Min-heap of busy rooms: (end_time, room)
        busy = []
        
        # Count meetings per room
        count = [0] * n
        
        for start, end in meetings:
            duration = end - start
            
            # Free rooms that have finished before current meeting starts
            while busy and busy[0][0] <= start:
                _, room = heapq.heappop(busy)
                heapq.heappush(available, room)
            
            if available:
                # Assign meeting to smallest available room
                room = heapq.heappop(available)
                heapq.heappush(busy, (end, room))
            else:
                # Delay meeting
                end_time, room = heapq.heappop(busy)
                heapq.heappush(busy, (end_time + duration, room))
            
            count[room] += 1
        
        # Find room with maximum meetings (tie → smallest index)
        max_meetings = max(count)
        for i in range(n):
            if count[i] == max_meetings:
                return i
