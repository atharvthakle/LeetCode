#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* s, int mask, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (left < n && ((mask >> left) & 1) == 0) left++;
        while (right >= 0 && ((mask >> right) & 1) == 0) right--;
        if (left >= right) break;
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int maxProduct(char* s) {
    int n = strlen(s);
    int maxMask = 1 << n;
    int result = 0;

    // Iterate over all pairs of subsequences
    for (int mask1 = 1; mask1 < maxMask; mask1++) {
        if (!isPalindrome(s, mask1, n)) continue;

        for (int mask2 = 1; mask2 < maxMask; mask2++) {
            if ((mask1 & mask2) != 0) continue; // Ensure disjoint
            if (!isPalindrome(s, mask2, n)) continue;

            // Count number of bits set in masks (lengths of subsequences)
            int len1 = 0, len2 = 0;
            for (int i = 0; i < n; i++) {
                if ((mask1 >> i) & 1) len1++;
                if ((mask2 >> i) & 1) len2++;
            }

            int product = len1 * len2;
            if (product > result) result = product;
        }
    }

    return result;
}
