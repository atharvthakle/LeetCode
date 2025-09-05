from collections import deque
from sortedcontainers import SortedList

class MKAverage:

    def __init__(self, m: int, k: int):
        self.m = m
        self.k = k
        self.stream = deque()
        self.sorted_window = SortedList()

    def addElement(self, num: int) -> None:
        self.stream.append(num)
        self.sorted_window.add(num)
        if len(self.stream) > self.m:
            # remove the oldest element
            oldest = self.stream.popleft()
            self.sorted_window.remove(oldest)

    def calculateMKAverage(self) -> int:
        if len(self.stream) < self.m:
            return -1
        # remove smallest k and largest k elements
        trimmed = self.sorted_window[self.k:self.m - self.k]
        return sum(trimmed) // len(trimmed)
