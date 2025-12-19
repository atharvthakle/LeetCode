class Solution:
    def findAllPeople(self, n: int, meetings: list[list[int]], firstPerson: int) -> list[int]:
        from collections import defaultdict

        # Union-Find (DSU)
        parent = list(range(n))

        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        def union(x, y):
            px, py = find(x), find(y)
            if px != py:
                parent[py] = px

        # People who know the secret
        knows = set([0, firstPerson])

        # Sort meetings by time
        meetings.sort(key=lambda x: x[2])

        i = 0
        while i < len(meetings):
            time = meetings[i][2]
            batch = []

            # Collect all meetings at the same time
            while i < len(meetings) and meetings[i][2] == time:
                x, y, _ = meetings[i]
                batch.append((x, y))
                i += 1

            # Temporarily union all meetings in this time frame
            involved = set()
            for x, y in batch:
                union(x, y)
                involved.add(x)
                involved.add(y)

            # Group people by component
            groups = defaultdict(list)
            for p in involved:
                groups[find(p)].append(p)

            # Spread the secret within components
            for group in groups.values():
                if any(p in knows for p in group):
                    knows.update(group)

            # Reset DSU for next time frame
            for p in involved:
                parent[p] = p

        return list(knows)
