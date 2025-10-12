#include <stdlib.h>
#include <string.h>

int countPrimes(int n) {
    if (n <= 2) return 0;

    // Create a boolean array to mark prime numbers
    char* isPrime = (char*)malloc(n);
    memset(isPrime, 1, n); // assume all numbers are prime initially

    isPrime[0] = 0;
    isPrime[1] = 0;

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = 0; // mark multiples as non-prime
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) count++;
    }

    free(isPrime);
    return count;
}
