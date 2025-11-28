class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        from collections import defaultdict
        graph = defaultdict(list)

        # Build adjacency list for the tree
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        self.components = 0

        def dfs(node, parent):
            total = values[node]  # subtree sum
            
            for nei in graph[node]:
                if nei != parent:
                    total += dfs(nei, node)

            # If subtree sum divisible by k, it's a valid component
            if total % k == 0:
                self.components += 1
                return 0  # return 0 to parent (cut here)

            return total

        dfs(0, -1)
        return self.components
