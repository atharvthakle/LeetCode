from typing import List
from collections import defaultdict

class Solution:
    def checkWays(self, pairs: List[List[int]]) -> int:
        graph = defaultdict(set)

        for u, v in pairs:
            graph[u].add(v)
            graph[v].add(u)

        nodes = list(graph.keys())
        n = len(nodes)

        root = -1
        for node in nodes:
            if len(graph[node]) == n - 1:
                root = node
                break

        if root == -1:
            return 0

        result = 1

        for node in nodes:
            if node == root:
                continue

            parent = -1
            parentDegree = float('inf')

            # Find parent: neighbor with smallest degree >= current degree
            for nei in graph[node]:
                if len(graph[nei]) >= len(graph[node]) and len(graph[nei]) < parentDegree:
                    parentDegree = len(graph[nei])
                    parent = nei

            if parent == -1:
                return 0

            # All neighbors except parent must also be neighbors of parent
            for nei in graph[node]:
                if nei == parent:
                    continue
                if nei not in graph[parent]:
                    return 0

            # Equal degrees => multiple valid trees
            if len(graph[parent]) == len(graph[node]):
                result = 2

        return result
