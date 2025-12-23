using System;
using System.Collections.Generic;

public class Solution {
    public int MaxTwoEvents(int[][] events) {
        // Sort events by start time
        Array.Sort(events, (a, b) => a[0].CompareTo(b[0]));

        // Min-heap by end time: (endTime, value)
        var pq = new PriorityQueue<(int end, int value), int>();

        int maxValueSoFar = 0;
        int result = 0;

        foreach (var e in events) {
            int start = e[0], end = e[1], value = e[2];

            // Remove all events that end before current start
            while (pq.Count > 0 && pq.Peek().end < start) {
                var finished = pq.Dequeue();
                maxValueSoFar = Math.Max(maxValueSoFar, finished.value);
            }

            // Combine current event with best previous
            result = Math.Max(result, maxValueSoFar + value);

            // Push current event
            pq.Enqueue((end, value), end);
        }

        return result;
    }
}
