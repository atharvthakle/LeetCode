int uniquePaths(int m, int n) {
    long long result = 1;
    int total = m + n - 2;
    int k = m - 1; // or n-1, whichever is smaller

    if (k > total - k) {
        k = total - k; // use smaller k for efficiency
    }

    for (int i = 1; i <= k; i++) {
        result = result * (total - k + i) / i;
    }

    return (int)result;
}
