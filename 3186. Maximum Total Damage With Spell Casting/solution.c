#include <stdlib.h>

// comparator for int array
int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

// binary search: find largest index <= highIdx such that unique[idx] <= value
// returns -1 if all unique[...] > value
int find_last_le(long long *unique, int highIdx, long long value) {
    int lo = 0, hi = highIdx;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (unique[mid] <= value) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

long long maximumTotalDamage(int* power, int powerSize) {
    if (powerSize == 0) return 0;

    // sort input
    qsort(power, powerSize, sizeof(int), cmp_int);

    // compress duplicates into unique values and total sums per value
    long long *unique = (long long*)malloc(sizeof(long long) * powerSize);
    long long *total = (long long*)malloc(sizeof(long long) * powerSize);
    int m = 0;

    unique[0] = power[0];
    total[0] = power[0];
    m = 1;
    for (int i = 1; i < powerSize; ++i) {
        if (power[i] == unique[m - 1]) {
            total[m - 1] += power[i];
        } else {
            unique[m] = power[i];
            total[m] = power[i];
            m++;
        }
    }

    // DP: dp[i] = best using first i unique values (0..i)
    long long *dp = (long long*)malloc(sizeof(long long) * m);
    dp[0] = total[0];

    for (int i = 1; i < m; ++i) {
        // find last index j with unique[j] <= unique[i] - 3
        long long limit = unique[i] - 3; // values <= limit are safe to combine
        int j = find_last_le(unique, i - 1, limit);

        long long take = total[i] + (j >= 0 ? dp[j] : 0);
        long long not_take = dp[i - 1];
        dp[i] = (take > not_take) ? take : not_take;
    }

    long long ans = dp[m - 1];
    free(unique);
    free(total);
    free(dp);
    return ans;
}
