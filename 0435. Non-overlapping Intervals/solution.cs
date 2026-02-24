using System;

public class Solution {
    public int EraseOverlapIntervals(int[][] intervals) {
        if (intervals.Length == 0) return 0;

        // Sort by end time
        Array.Sort(intervals, (a, b) => a[1].CompareTo(b[1]));

        int count = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.Length; i++) {
            if (intervals[i][0] < prevEnd) {
                // Overlapping → remove this interval
                count++;
            } else {
                // Non-overlapping → keep it
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
}
