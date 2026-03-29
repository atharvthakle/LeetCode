from typing import List

class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)

        # Step 1: check diagonal
        for i in range(n):
            if lcp[i][i] != n - i:
                return ""

        # Step 2: DSU (Union-Find)
        parent = list(range(n))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa != pb:
                parent[pb] = pa

        # union based on lcp > 0
        for i in range(n):
            for j in range(i + 1, n):
                if lcp[i][j] > 0:
                    union(i, j)

        # Step 3: assign characters
        group_map = {}
        res = [''] * n
        curr_char = 0

        for i in range(n):
            root = find(i)
            if root not in group_map:
                if curr_char >= 26:
                    return ""
                group_map[root] = chr(ord('a') + curr_char)
                curr_char += 1
            res[i] = group_map[root]

        word = "".join(res)

        # Step 4: validate LCP
        dp = [[0]*n for _ in range(n)]

        for i in range(n-1, -1, -1):
            for j in range(n-1, -1, -1):
                if word[i] == word[j]:
                    if i+1 < n and j+1 < n:
                        dp[i][j] = dp[i+1][j+1] + 1
                    else:
                        dp[i][j] = 1
                else:
                    dp[i][j] = 0

                if dp[i][j] != lcp[i][j]:
                    return ""

        return word
