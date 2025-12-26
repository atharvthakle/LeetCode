from bisect import bisect_left
from typing import List

class SummaryRanges:

    def __init__(self):
        # Each interval is [start, end], sorted by start
        self.intervals = []

    def addNum(self, value: int) -> None:
        intervals = self.intervals
        i = bisect_left(intervals, [value, value])

        # Merge with left interval if possible
        left_merge = (i > 0 and intervals[i - 1][1] + 1 >= value)
        # Merge with right interval if possible
        right_merge = (i < len(intervals) and intervals[i][0] - 1 <= value)

        if left_merge and right_merge:
            # Merge left and right intervals
            intervals[i - 1][1] = max(intervals[i - 1][1], intervals[i][1])
            intervals.pop(i)
        elif left_merge:
            # Extend left interval
            intervals[i - 1][1] = max(intervals[i - 1][1], value)
        elif right_merge:
            # Extend right interval
            intervals[i][0] = min(intervals[i][0], value)
        else:
            # Create new interval
            intervals.insert(i, [value, value])

    def getIntervals(self) -> List[List[int]]:
        return self.intervals
