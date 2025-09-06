import heapq

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        # Pair each project with its capital requirement
        projects = sorted(zip(capital, profits))
        max_profit_heap = []
        i = 0
        n = len(profits)
        
        for _ in range(k):
            # Push all projects whose capital requirement <= current capital into max heap
            while i < n and projects[i][0] <= w:
                # Use negative profit because heapq is a min-heap
                heapq.heappush(max_profit_heap, -projects[i][1])
                i += 1
            
            if not max_profit_heap:
                # Cannot afford any more projects
                break
            
            # Select the project with max profit
            w += -heapq.heappop(max_profit_heap)
        
        return w
