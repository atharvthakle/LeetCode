using System;
using System.Collections.Generic;

public class Solution {
    public int MinMirrorPairDistance(int[] nums) {
        var map = new Dictionary<int, int>();
        int res = int.MaxValue;

        for (int i = 0; i < nums.Length; i++) {
            int num = nums[i];

            // check if this number was someone else's reverse
            if (map.ContainsKey(num)) {
                res = Math.Min(res, i - map[num]);
            }

            // store reverse of current number
            int rev = Reverse(num);
            map[rev] = i;
        }

        return res == int.MaxValue ? -1 : res;
    }

    private int Reverse(int x) {
        int res = 0;
        while (x > 0) {
            res = res * 10 + (x % 10);
            x /= 10;
        }
        return res;
    }
}
