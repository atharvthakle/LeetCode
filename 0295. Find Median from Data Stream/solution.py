import heapq

class MedianFinder:

    def __init__(self):
        # max-heap for the smaller half (invert numbers for max-heap)
        self.small = []
        # min-heap for the larger half
        self.large = []

    def addNum(self, num: int) -> None:
        # Add to max-heap (small)
        heapq.heappush(self.small, -num)
        # Balance: move the largest of small to large
        heapq.heappush(self.large, -heapq.heappop(self.small))
        
        # Maintain size property: small can have at most 1 more element than large
        if len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def findMedian(self) -> float:
        if len(self.small) > len(self.large):
            return -self.small[0]  # max of small
        else:
            return (-self.small[0] + self.large[0]) / 2  # average of two middles
