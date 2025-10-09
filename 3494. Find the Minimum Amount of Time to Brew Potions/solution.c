#include <stdlib.h>
#include <limits.h>

long long minTime(int* skill, int skillSize, int* mana, int manaSize) {
    int n = skillSize;
    int m = manaSize;
    // skillPrefix[i] = sum_{t=0..i} skill[t]
    long long *skillPref = (long long*)malloc(sizeof(long long) * n);
    if (!skillPref) return 0;
    skillPref[0] = (long long)skill[0];
    for (int i = 1; i < n; ++i) skillPref[i] = skillPref[i-1] + (long long)skill[i];

    long long S = 0; // S_j for current potion j (we keep S_j and accumulate D_j)
    for (int j = 0; j < m - 1; ++j) {
        long long maxTerm = LLONG_MIN;
        long long mana_j = (long long)mana[j];
        long long mana_j1 = (long long)mana[j+1];

        // compute D_j = max_i ( mana_j * skillPref[i] - mana_{j+1} * skillPref[i-1] )
        for (int i = 0; i < n; ++i) {
            long long term;
            if (i == 0) {
                // pref_j[0] - pref_{j+1}[-1] = mana_j * skillPref[0] - 0
                term = mana_j * skillPref[0];
            } else {
                term = mana_j * skillPref[i] - mana_j1 * skillPref[i-1];
            }
            if (term > maxTerm) maxTerm = term;
        }
        if (maxTerm < 0) maxTerm = 0; // just in case (though term >= 0 for i=0)
        S += maxTerm;
    }

    // final completion time = S_{m-1} + pref_{m-1}[n-1]
    long long result = S + (long long)mana[m-1] * skillPref[n-1];
    free(skillPref);
    return result;
}
\
