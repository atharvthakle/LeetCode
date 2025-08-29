from typing import List
from collections import deque

class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def isValid(string: str) -> bool:
            count = 0
            for ch in string:
                if ch == '(':
                    count += 1
                elif ch == ')':
                    count -= 1
                    if count < 0:
                        return False
            return count == 0

        res = []
        visited = set()
        queue = deque([s])
        visited.add(s)
        found = False

        while queue:
            curr = queue.popleft()
            if isValid(curr):
                res.append(curr)
                found = True
            if found:
                continue
            for i in range(len(curr)):
                if curr[i] not in ('(', ')'):
                    continue
                newStr = curr[:i] + curr[i+1:]
                if newStr not in visited:
                    visited.add(newStr)
                    queue.append(newStr)

        return res
