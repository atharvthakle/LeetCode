public class Solution {
    public int SumFourDivisors(int[] nums) {
        int result = 0;

        foreach (int num in nums) {
            int sum = 0;
            int count = 0;

            for (int d = 1; d * d <= num; d++) {
                if (num % d == 0) {
                    int other = num / d;

                    if (d == other) {
                        count++;
                        sum += d;
                    } else {
                        count += 2;
                        sum += d + other;
                    }

                    if (count > 4)
                        break;
                }
            }

            if (count == 4)
                result += sum;
        }

        return result;
    }
}
