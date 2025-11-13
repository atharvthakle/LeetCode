#include <string.h>

int maxOperations(char* s) {
    long long ones = 0;
    long long ans = 0;
    int n = (int)strlen(s);
    if (n == 0) return 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ++ones;
        } else { // s[i] == '0'
            // start of a zero-block if previous char is '1'
            if (i > 0 && s[i-1] == '1' && ones > 0) {
                ans += ones;
            }
        }
    }

    // ans fits in 64-bit; function signature returns int per problem,
    // return cast to int (LeetCode constraints guarantee it fits).
    return (int)ans;
}
