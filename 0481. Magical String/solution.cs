public class Solution {
    public int MagicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;

        List<int> s = new List<int> { 1, 2, 2 };

        int i = 2;          // pointer for counts
        int num = 1;        // next number to append
        int countOnes = 1;  // already have one '1'

        while (s.Count < n) {
            int repeat = s[i];

            for (int j = 0; j < repeat && s.Count < n; j++) {
                s.Add(num);
                if (num == 1) countOnes++;
            }

            num = 3 - num; // toggle between 1 and 2
            i++;
        }

        return countOnes;
    }
}
