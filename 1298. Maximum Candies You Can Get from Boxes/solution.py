from collections import deque
from typing import List

class Solution:
    def maxCandies(
        self,
        status: List[int],
        candies: List[int],
        keys: List[List[int]],
        containedBoxes: List[List[int]],
        initialBoxes: List[int]
    ) -> int:
        n = len(status)
        haveBox = [False] * n
        canOpen = status[:]  # if already open (1) or closed (0)

        q = deque()
        for b in initialBoxes:
            haveBox[b] = True
            if canOpen[b]:
                q.append(b)

        total = 0
        while q:
            box = q.popleft()
            total += candies[box]

            # gain keys
            for k in keys[box]:
                if not canOpen[k]:
                    canOpen[k] = 1
                    if haveBox[k]:  # we already have this box, now we can open it
                        q.append(k)

            # gain boxes
            for b in containedBoxes[box]:
                if not haveBox[b]:
                    haveBox[b] = True
                    if canOpen[b]:
                        q.append(b)

        return total
