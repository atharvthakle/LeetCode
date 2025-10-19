#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int gcd_int(int a, int b){
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

char* findLexSmallestString(char* s, int a, int b) {
    int n = strlen(s);
    int g = gcd_int(n, b);
    // allocate string for minimal answer, initialize with s
    char *best = (char*)malloc(n + 1);
    strcpy(best, s);

    char *rot = (char*)malloc(n + 1);
    char *cand = (char*)malloc(n + 1);

    for (int r = 0; r < n; r += g) {
        // create rotation: rotate right by r
        for (int i = 0; i < n; ++i) {
            int src = (i - r) % n;
            if (src < 0) src += n;
            rot[i] = s[src];
        }
        rot[n] = '\0';

        // try all kx = 0..9 times of add applied to odd indices
        for (int kx = 0; kx < 10; ++kx) {
            int addOdd = (kx * a) % 10;

            if ( (b & 1) == 1 ) {
                // b is odd -> parity can be changed via rotation + add sequence
                for (int ky = 0; ky < 10; ++ky) {
                    int addEven = (ky * a) % 10;

                    for (int i = 0; i < n; ++i) {
                        int digit = rot[i] - '0';
                        if ( (i & 1) == 1 ) digit = (digit + addOdd) % 10;
                        else digit = (digit + addEven) % 10;
                        cand[i] = (char)('0' + digit);
                    }
                    cand[n] = '\0';
                    if (strcmp(cand, best) < 0) strcpy(best, cand);
                }
            } else {
                // b is even -> parity is fixed, only odd indices change
                for (int i = 0; i < n; ++i) {
                    int digit = rot[i] - '0';
                    if ( (i & 1) == 1 ) digit = (digit + addOdd) % 10;
                    cand[i] = (char)('0' + digit);
                }
                cand[n] = '\0';
                if (strcmp(cand, best) < 0) strcpy(best, cand);
            }
        }
    }

    free(rot);
    free(cand);
    return best; // caller should free()
}
