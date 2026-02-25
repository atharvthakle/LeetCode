using System;

public class Solution {
    public int[] FindRightInterval(int[][] intervals) {
        int n = intervals.Length;
        int[] result = new int[n];

        // Store (start, original index)
        (int start, int index)[] starts = new (int, int)[n];
        for (int i = 0; i < n; i++) {
            starts[i] = (intervals[i][0], i);
        }

        // Sort by start value
        Array.Sort(starts, (a, b) => a.start.CompareTo(b.start));

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            int idx = BinarySearch(starts, end);
            result[i] = idx;
        }

        return result;
    }

    private int BinarySearch((int start, int index)[] starts, int target) {
        int left = 0, right = starts.Length - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (starts[mid].start >= target) {
                answer = starts[mid].index;
                right = mid - 1; // try to find smaller valid start
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
}
