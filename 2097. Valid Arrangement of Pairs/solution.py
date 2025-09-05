from typing import List
from collections import defaultdict, deque

class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        graph = defaultdict(deque)
        indeg, outdeg = defaultdict(int), defaultdict(int)
        
        # Build graph and track in/out degrees
        for u, v in pairs:
            graph[u].append(v)
            outdeg[u] += 1
            indeg[v] += 1
        
        # Find starting node for Eulerian path
        start = pairs[0][0]
        for node in graph:
            if outdeg[node] - indeg[node] == 1:  # Eulerian path start
                start = node
                break
        
        result = []
        
        def dfs(u):
            while graph[u]:
                v = graph[u].popleft()
                dfs(v)
                result.append([u, v])
        
        dfs(start)
        return result[::-1]
