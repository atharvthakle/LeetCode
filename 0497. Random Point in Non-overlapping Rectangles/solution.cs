using System;

public class Solution {

    private int[][] rects;
    private int[] prefix;
    private int total;
    private Random rand;

    public Solution(int[][] rects) {
        this.rects = rects;
        int n = rects.Length;
        prefix = new int[n];
        rand = new Random();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int[] r = rects[i];
            int count = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sum += count;
            prefix[i] = sum;
        }

        total = sum;
    }
    
    public int[] Pick() {
        int target = rand.Next(1, total + 1);

        // binary search
        int left = 0, right = prefix.Length - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (prefix[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        int[] r = rects[left];

        int x = rand.Next(r[0], r[2] + 1);
        int y = rand.Next(r[1], r[3] + 1);

        return new int[] { x, y };
    }
}
