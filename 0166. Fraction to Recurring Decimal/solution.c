#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Hash map for storing remainder positions
#define HASH_SIZE 20003
struct HashNode {
    long long rem;
    int pos;
    struct HashNode* next;
};

int hashFunc(long long rem) {
    return (rem % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

void insertHash(struct HashNode** hash, long long rem, int pos) {
    int idx = hashFunc(rem);
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->rem = rem;
    newNode->pos = pos;
    newNode->next = hash[idx];
    hash[idx] = newNode;
}

int searchHash(struct HashNode** hash, long long rem) {
    int idx = hashFunc(rem);
    struct HashNode* cur = hash[idx];
    while (cur) {
        if (cur->rem == rem) return cur->pos;
        cur = cur->next;
    }
    return -1;
}

char* fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
        char* res = (char*)malloc(2);
        strcpy(res, "0");
        return res;
    }

    char* res = (char*)malloc(10050); // guaranteed < 10^4 length
    int idx = 0;

    // Handle sign
    if ((numerator < 0) ^ (denominator < 0)) {
        res[idx++] = '-';
    }

    long long num = llabs((long long)numerator);
    long long den = llabs((long long)denominator);

    // Integer part
    long long integerPart = num / den;
    idx += sprintf(res + idx, "%lld", integerPart);

    long long rem = num % den;
    if (rem == 0) {
        res[idx] = '\0';
        return res;
    }

    res[idx++] = '.';

    // Hash map for detecting cycles
    struct HashNode* hash[HASH_SIZE] = {0};

    while (rem != 0) {
        int repeatPos = searchHash(hash, rem);
        if (repeatPos != -1) {
            // Insert '(' at repeatPos
            memmove(res + repeatPos + 1, res + repeatPos, idx - repeatPos);
            res[repeatPos] = '(';
            idx++;
            res[idx++] = ')';
            res[idx] = '\0';
            return res;
        }
        insertHash(hash, rem, idx);

        rem *= 10;
        long long digit = rem / den;
        res[idx++] = '0' + digit;
        rem %= den;
    }

    res[idx] = '\0';
    return res;
}
