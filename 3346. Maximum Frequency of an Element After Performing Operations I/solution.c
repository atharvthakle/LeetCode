#include <stdlib.h>
#include <string.h>

int cmp_int(const void *a, const void *b){
    int x = *(int*)a; int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}
int cmp_ll(const void *a, const void *b){
    long long x = *(long long*)a; long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

/* lower_bound: first index >= val */
int lower_bound_ll(long long *arr, int n, long long val){
    int l = 0, r = n;
    while (l < r){
        int m = (l + r) >> 1;
        if (arr[m] < val) l = m + 1;
        else r = m;
    }
    return l;
}

/* upper_bound: first index > val */
int upper_bound_ll(long long *arr, int n, long long val){
    int l = 0, r = n;
    while (l < r){
        int m = (l + r) >> 1;
        if (arr[m] <= val) l = m + 1;
        else r = m;
    }
    return l;
}

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    if (numsSize == 0) return 0;
    qsort(nums, numsSize, sizeof(int), cmp_int);

    // Build starts and ends of intervals [nums[i]-k, nums[i]+k]
    long long *starts = (long long*)malloc(sizeof(long long) * numsSize);
    long long *ends   = (long long*)malloc(sizeof(long long) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        starts[i] = (long long)nums[i] - (long long)k;
        ends[i]   = (long long)nums[i] + (long long)k;
    }
    qsort(starts, numsSize, sizeof(long long), cmp_ll);
    qsort(ends,   numsSize, sizeof(long long), cmp_ll);

    // Compute maximum overlap across all T (for possible T not equal to any nums value)
    int i = 0, j = 0, cur = 0, maxOverlap = 0;
    while (i < numsSize) {
        if (j >= numsSize || starts[i] <= ends[j]) {
            cur++;
            if (cur > maxOverlap) maxOverlap = cur;
            i++;
        } else {
            cur--;
            j++;
        }
    }

    int answer = 0;
    // Candidate from T not equal to any nums: at most numOperations or maxOverlap whichever smaller
    if (numOperations > 0) {
        int cand_non_num = (maxOverlap < numOperations) ? maxOverlap : numOperations;
        if (cand_non_num > answer) answer = cand_non_num;
    }

    // Evaluate f(T) for each distinct value T present in nums
    int idx = 0;
    while (idx < numsSize) {
        int val = nums[idx];
        // count equal elements
        int startIdx = idx;
        while (idx < numsSize && nums[idx] == val) idx++;
        int eq = idx - startIdx;

        // total_in_interval = number of intervals that contain val
        int cntStartLE = upper_bound_ll(starts, numsSize, (long long)val);        // starts <= val
        int cntEndLT   = lower_bound_ll(ends, numsSize, (long long)val);         // ends < val
        int total_in_interval = cntStartLE - cntEndLT;

        int candidate = total_in_interval;
        int limit = eq + numOperations;
        if (limit < candidate) candidate = limit;

        if (candidate > answer) answer = candidate;
    }

    free(starts);
    free(ends);
    return answer;
}
