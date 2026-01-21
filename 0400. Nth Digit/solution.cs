public class Solution {
    public int FindNthDigit(int n) {
        long len = 1;       // current digit length
        long count = 9;     // how many numbers in this group
        long start = 1;     // starting number of this group

        // Locate the group where nth digit lies
        while (n > len * count) {
            n -= (int)(len * count);
            len++;
            count *= 10;
            start *= 10;
        }

        // Find the exact number
        long number = start + (n - 1) / len;

        // Find the digit index within the number
        int index = (int)((n - 1) % len);

        return number.ToString()[index] - '0';
    }
}
