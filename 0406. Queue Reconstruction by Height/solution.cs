using System;
using System.Collections.Generic;

public class Solution {
    public int[][] ReconstructQueue(int[][] people) {
        // Sort by height descending, then k ascending
        Array.Sort(people, (a, b) => {
            if (a[0] != b[0]) 
                return b[0].CompareTo(a[0]);
            return a[1].CompareTo(b[1]);
        });

        List<int[]> queue = new List<int[]>();

        // Insert each person at index k
        foreach (var person in people) {
            queue.Insert(person[1], person);
        }

        return queue.ToArray();
    }
}
