#define MOD 1000000007

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int monkeyMove(int n) {
    long long total = modPow(2, n, MOD);
    long long ans = (total - 2 + MOD) % MOD;  // handle negative
    return (int)ans;
}
