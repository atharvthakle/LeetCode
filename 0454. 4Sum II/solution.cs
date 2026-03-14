using System.Collections.Generic;

public class Solution {
    public int FourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Dictionary<int, int> map = new Dictionary<int, int>();

        foreach (int a in nums1) {
            foreach (int b in nums2) {
                int sum = a + b;
                if (!map.ContainsKey(sum))
                    map[sum] = 0;
                map[sum]++;
            }
        }

        int count = 0;

        foreach (int c in nums3) {
            foreach (int d in nums4) {
                int target = -(c + d);
                if (map.ContainsKey(target)) {
                    count += map[target];
                }
            }
        }

        return count;
    }
}
