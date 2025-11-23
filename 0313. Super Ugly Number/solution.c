#include <limits.h>
#include <stdlib.h>

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int* ugly = (int*)malloc(sizeof(int) * n);
    int* idx = (int*)malloc(sizeof(int) * primesSize);
    int* next = (int*)malloc(sizeof(int) * primesSize);
    
    for (int i = 0; i < primesSize; i++) {
        idx[i] = 0;       // pointer for each prime
        next[i] = primes[i]; // next multiple of prime[i]
    }
    
    ugly[0] = 1;
    
    for (int i = 1; i < n; i++) {
        // Find the next ugly number
        int nextUgly = INT_MAX;
        for (int j = 0; j < primesSize; j++) {
            if (next[j] < nextUgly) nextUgly = next[j];
        }
        ugly[i] = nextUgly;
        
        // Update pointers for primes that match nextUgly
        for (int j = 0; j < primesSize; j++) {
            if (next[j] == nextUgly) {
                idx[j]++;
                next[j] = ugly[idx[j]] * primes[j];
            }
        }
    }
    
    int result = ugly[n - 1];
    free(ugly);
    free(idx);
    free(next);
    
    return result;
}
