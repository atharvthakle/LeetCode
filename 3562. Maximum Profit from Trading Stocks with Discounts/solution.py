from typing import List
from math import inf

class Solution:
    def maxProfit(self, n: int, present: List[int], future: List[int], hierarchy: List[List[int]], budget: int) -> int:
        # Build adjacency (tree rooted at 0)
        tree = [[] for _ in range(n)]
        parent = [-1]*n
        for u,v in hierarchy:
            u -= 1; v -= 1
            tree[u].append(v)
            parent[v] = u

        # Merge two DP arrays A and B (knapsack convolution)
        def merge(A, B):
            R = [-inf] * (budget + 1)
            for i in range(budget + 1):
                if A[i] == -inf:
                    continue
                # j up to budget - i
                limit = budget - i
                # iterate over j where B[j] is valid
                # small optimization: check B[j] != -inf inside loop
                for j in range(limit + 1):
                    if B[j] == -inf:
                        continue
                    val = A[i] + B[j]
                    if val > R[i + j]:
                        R[i + j] = val
            return R

        # DFS returns tuple (dp_no_parent, dp_yes_parent)
        def dfs(u):
            # Start with "not buying u" base: cost 0 profit 0
            not_buy = [ -inf ] * (budget + 1)
            not_buy[0] = 0

            # For "buying u" when parent did NOT buy (full price)
            cost_full = present[u]
            profit_full = future[u] - cost_full
            buy_full = [ -inf ] * (budget + 1)
            if cost_full <= budget:
                buy_full[cost_full] = profit_full

            # For "buying u" when parent DID buy (discount price)
            cost_disc = present[u] // 2
            profit_disc = future[u] - cost_disc
            buy_disc = [ -inf ] * (budget + 1)
            if cost_disc <= budget:
                buy_disc[cost_disc] = profit_disc

            # Process children
            for v in tree[u]:
                child_no, child_yes = dfs(v)
                # If u is NOT bought, child's parent is NOT bought -> merge with child_no
                not_buy = merge(not_buy, child_no)
                # If u IS bought and we consider u bought at full price, child gets parent bought -> merge with child_yes
                buy_full = merge(buy_full, child_yes)
                # If u IS bought at discounted price (parent of u bought), child also sees parent bought
                buy_disc = merge(buy_disc, child_yes)

            # dp when parent's state = NOT bought:
            # u may choose not to buy (not_buy) or buy at full price (buy_full)
            dp_no_parent = [ -inf ] * (budget + 1)
            for b in range(budget + 1):
                a = not_buy[b]
                c = buy_full[b]
                dp_no_parent[b] = a if a >= c else c

            # dp when parent's state = YES (parent bought):
            # u may choose not to buy (not_buy) or buy at discounted price (buy_disc)
            dp_yes_parent = [ -inf ] * (budget + 1)
            for b in range(budget + 1):
                a = not_buy[b]
                c = buy_disc[b]
                dp_yes_parent[b] = a if a >= c else c

            return dp_no_parent, dp_yes_parent

        # Run DFS from the CEO = node with parent == -1 (problem states employee 1 is boss; index 0)
        # If input guaranteed CEO = 1, start at 0.
        root = 0
        dp_root_no, dp_root_yes = dfs(root)

        # Root has no parent => use dp_root_no, answer is max profit over budgets <= budget
        ans = max(dp_root_no)
        if ans == -inf:
            return 0
        return ans
