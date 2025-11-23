#include <limits.h>
#include <stdlib.h>

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int* ugly = (int*)malloc(sizeof(int) * n);
    int* idx = (int*)malloc(sizeof(int) * primesSize);
    long long* next = (long long*)malloc(sizeof(long long) * primesSize); // use long long
    
    for (int i = 0; i < primesSize; i++) {
        idx[i] = 0;          
        next[i] = primes[i]; // next multiple of prime[i]
    }
    
    ugly[0] = 1;
    
    for (int i = 1; i < n; i++) {
        // Find the next ugly number
        long long nextUgly = LLONG_MAX;
        for (int j = 0; j < primesSize; j++) {
            if (next[j] < nextUgly) nextUgly = next[j];
        }
        ugly[i] = (int)nextUgly; // safe to cast
        
        // Update pointers for primes that match nextUgly
        for (int j = 0; j < primesSize; j++) {
            if (next[j] == nextUgly) {
                idx[j]++;
                next[j] = (long long)ugly[idx[j]] * primes[j]; // use long long multiplication
            }
        }
    }
    
    int result = ugly[n - 1];
    free(ugly);
    free(idx);
    free(next);
    
    return result;
}
