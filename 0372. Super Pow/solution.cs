public class Solution {
    private const int MOD = 1337;

    public int SuperPow(int a, int[] b) {
        int result = 1;
        a %= MOD;

        foreach (int digit in b) {
            // result = (result^10 * a^digit) % MOD
            result = PowMod(result, 10);
            result = (result * PowMod(a, digit)) % MOD;
        }

        return result;
    }

    private int PowMod(int baseVal, int exp) {
        int res = 1;
        baseVal %= MOD;

        for (int i = 0; i < exp; i++) {
            res = (res * baseVal) % MOD;
        }

        return res;
    }
}
