import heapq

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        # Step 1: Convert buildings into start and end events
        events = []
        for left, right, height in buildings:
            events.append((left, -height, right))  # start of building
            events.append((right, 0, 0))           # end of building
        
        # Step 2: Sort events by position
        # Sort by x; if same x, process higher starts before lower or ends
        events.sort()
        
        # Step 3: Initialize heap and result
        result = [[0, 0]]
        heap = [(0, float("inf"))]  # (negative height, right boundary)
        
        # Step 4: Sweep line
        for x, neg_h, r in events:
            # Remove all buildings that ended before x
            while heap and heap[0][1] <= x:
                heapq.heappop(heap)
            
            # If it's the start of a building, add to heap
            if neg_h != 0:
                heapq.heappush(heap, (neg_h, r))
            
            # Current max height
            curr_height = -heap[0][0]
            
            # If skyline height changed, record new key point
            if result[-1][1] != curr_height:
                result.append([x, curr_height])
        
        # Step 5: Return result excluding the initial dummy point
        return result[1:]
