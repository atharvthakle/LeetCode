public class Solution {
    public int CountNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        int result = 1;          // count for x = 0
        int current = 9;         // unique numbers with 1 digit
        int available = 9;       // digits left to use

        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                result += current;
            } else {
                current *= available;
                result += current;
                available--;
            }
        }

        return result;
    }
}
