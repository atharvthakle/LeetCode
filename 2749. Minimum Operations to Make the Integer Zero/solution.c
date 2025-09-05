int makeTheIntegerZero(int num1, int num2) {
    for (int k = 1; k <= 60; k++) {
        long long diff = (long long)num1 - (long long)k * num2;
        if (diff < k) continue;  // too small, can't represent
        int bits = __builtin_popcountll(diff);  // number of set bits
        if (bits <= k && diff >= k) {
            return k;
        }
    }
    return -1;
}
