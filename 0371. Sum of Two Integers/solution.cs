public class Solution {
    public int GetSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1; // carry bits
            a = a ^ b;               // sum without carry
            b = carry;               // add carry in next iteration
        }
        return a;
    }
}
