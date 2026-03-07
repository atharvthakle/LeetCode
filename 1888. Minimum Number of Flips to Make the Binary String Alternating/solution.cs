public class Solution {
    public int MinFlips(string s) {
        int n = s.Length;
        string ss = s + s;

        int diff1 = 0, diff2 = 0;
        int res = int.MaxValue;

        for (int i = 0; i < ss.Length; i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if (ss[i] != expected1) diff1++;
            if (ss[i] != expected2) diff2++;

            if (i >= n) {
                char prevExpected1 = ((i - n) % 2 == 0) ? '0' : '1';
                char prevExpected2 = ((i - n) % 2 == 0) ? '1' : '0';

                if (ss[i - n] != prevExpected1) diff1--;
                if (ss[i - n] != prevExpected2) diff2--;
            }

            if (i >= n - 1) {
                res = Math.Min(res, Math.Min(diff1, diff2));
            }
        }

        return res;
    }
}
