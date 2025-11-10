#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

/* Helper: build log table */
static void buildLogs(int n, int *lg) {
    lg[1] = 0;
    for (int i = 2; i <= n; ++i) lg[i] = lg[i/2] + 1;
}

/* Sparse-table RMQ storing index of minimum element */
static int **buildSparseTable(int *nums, int n, int *lg) {
    int K = lg[n] + 1;
    int **st = (int**)malloc((K) * sizeof(int*));
    for (int k = 0; k < K; ++k) st[k] = (int*)malloc(n * sizeof(int));
    /* level 0: index itself */
    for (int i = 0; i < n; ++i) st[0][i] = i;
    for (int k = 1; k < K; ++k) {
        int len = 1 << (k - 1);
        for (int i = 0; i + (1<<k) - 1 < n; ++i) {
            int a = st[k-1][i];
            int b = st[k-1][i + len];
            /* choose index with smaller value; tie choose left index */
            if (nums[a] <= nums[b]) st[k][i] = a;
            else st[k][i] = b;
        }
    }
    return st;
}

static int rmqIndex(int **st, int *nums, int *lg, int l, int r) {
    int len = r - l + 1;
    int k = lg[len];
    int a = st[k][l];
    int b = st[k][r - (1<<k) + 1];
    return (nums[a] <= nums[b]) ? a : b;
}

/* binary search lower_bound on array arr[len] */
static int lower_bound_idx(int *arr, int len, int target) {
    int lo = 0, hi = len; /* [lo,hi) */
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

static int upper_bound_idx(int *arr, int len, int target) {
    int lo = 0, hi = len; /* [lo,hi) */
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (arr[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

/* Recursive DP on interval [l,r] with nums strictly > 0 */
static int solveInterval(int *nums, int n, int l, int r,
                         int **st, int *lg,
                         int maxVal,
                         int *posCount, int **positions) {
    if (l > r) return 0;
    /* Option to remove every element individually */
    int best = r - l + 1;

    int idx = rmqIndex(st, nums, lg, l, r);
    int m = nums[idx];

    /* find occurrences of value m in [l,r] using positions[m] */
    int *posArr = positions[m];
    int cnt = posCount[m];
    if (cnt == 0) {
        /* shouldn't happen because idx has that value */
        return best;
    }
    int lo = lower_bound_idx(posArr, cnt, l);
    int hi = upper_bound_idx(posArr, cnt, r); /* exclusive */
    if (lo >= hi) {
        /* no occurrences in [l,r] (shouldn't happen) */
        return best;
    }

    /* 1 operation for removing all m in [l,r], plus sum over subsegments between these positions */
    int sum = 1;
    int prev = l;
    for (int t = lo; t < hi; ++t) {
        int p = posArr[t];
        if (prev <= p - 1) {
            sum += solveInterval(nums, n, prev, p - 1, st, lg, maxVal, posCount, positions);
            /* small optimization: if sum already >= best, we can break early */
            if (sum >= best) break;
        }
        prev = p + 1;
    }
    if (sum < best && prev <= r) {
        sum += solveInterval(nums, n, prev, r, st, lg, maxVal, posCount, positions);
    }
    if (sum < best) best = sum;
    return best;
}

int minOperations(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    /* find maxVal to allocate positions arrays */
    int maxVal = 0;
    for (int i = 0; i < numsSize; ++i) if (nums[i] > maxVal) maxVal = nums[i];

    /* pre-count occurrences for each value */
    int mV = maxVal;
    int *posCount = (int*)calloc((mV + 1), sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        int v = nums[i];
        posCount[v]++;
    }

    /* allocate positions arrays and fill */
    int **positions = (int**)malloc((mV + 1) * sizeof(int*));
    for (int v = 0; v <= mV; ++v) {
        if (posCount[v] > 0) positions[v] = (int*)malloc(posCount[v] * sizeof(int));
        else positions[v] = NULL;
    }
    /* fill with indices */
    int *tmpFill = (int*)calloc((mV + 1), sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        int v = nums[i];
        positions[v][tmpFill[v]++] = i;
    }
    free(tmpFill);

    /* build logs and sparse table for RMQ */
    int *lg = (int*)malloc((numsSize + 1) * sizeof(int));
    buildLogs(numsSize, lg);
    int **st = buildSparseTable(nums, numsSize, lg);

    /* process only positive segments (zeros split) */
    int result = 0;
    int i = 0;
    while (i < numsSize) {
        while (i < numsSize && nums[i] == 0) ++i;
        if (i >= numsSize) break;
        int start = i;
        while (i < numsSize && nums[i] > 0) ++i;
        int end = i - 1;
        result += solveInterval(nums, numsSize, start, end, st, lg, mV, posCount, positions);
    }

    /* cleanup */
    for (int k = 0; k <= lg[numsSize]; ++k) free(st[k]);
    free(st);
    free(lg);
    for (int v = 0; v <= mV; ++v) {
        if (positions[v]) free(positions[v]);
    }
    free(positions);
    free(posCount);

    return result;
}
