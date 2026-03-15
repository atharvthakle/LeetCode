using System.Collections.Generic;

public class Solution {
    Dictionary<int, bool> memo = new Dictionary<int, bool>();

    public bool CanIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;

        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sum < desiredTotal) return false;

        return DFS(0, desiredTotal, maxChoosableInteger);
    }

    private bool DFS(int usedMask, int remain, int maxNum) {
        if (memo.ContainsKey(usedMask))
            return memo[usedMask];

        for (int i = 1; i <= maxNum; i++) {
            int bit = 1 << (i - 1);

            if ((usedMask & bit) != 0) continue;

            if (i >= remain || !DFS(usedMask | bit, remain - i, maxNum)) {
                memo[usedMask] = true;
                return true;
            }
        }

        memo[usedMask] = false;
        return false;
    }
}
