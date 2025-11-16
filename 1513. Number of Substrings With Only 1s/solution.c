int numSub(char* s) {
    const long long MOD = 1000000007;
    long long ans = 0;
    long long count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '1') {
            count++;
        } else {
            ans = (ans + (count * (count + 1) / 2) % MOD) % MOD;
            count = 0;
        }
    }

    // Add the final segment if it ends with '1'
    ans = (ans + (count * (count + 1) / 2) % MOD) % MOD;

    return (int)ans;
}
