#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 20011  // big prime

typedef struct {
    char* key;
    char* val;
} Entry;

typedef struct {
    Entry* table;
} HashMap;

unsigned long hashStr(const char* s) {
    unsigned long h = 0;
    while (*s) h = h * 131 + (unsigned char)(*s++);
    return h;
}

HashMap* createMap() {
    HashMap* m = (HashMap*)malloc(sizeof(HashMap));
    m->table = (Entry*)calloc(HASH_SIZE, sizeof(Entry));
    return m;
}

void insertMap(HashMap* m, const char* key, const char* val) {
    unsigned long h = hashStr(key) % HASH_SIZE;
    while (m->table[h].key) {
        if (strcmp(m->table[h].key, key) == 0) return; // keep first value
        h = (h + 1) % HASH_SIZE;
    }
    m->table[h].key = strdup(key);
    m->table[h].val = strdup(val);
}

char* getMap(HashMap* m, const char* key) {
    unsigned long h = hashStr(key) % HASH_SIZE;
    while (m->table[h].key) {
        if (strcmp(m->table[h].key, key) == 0)
            return m->table[h].val;
        h = (h + 1) % HASH_SIZE;
    }
    return NULL;
}

int isVowel(char c) {
    c = tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

char* toLowerStr(const char* s) {
    int n = strlen(s);
    char* res = (char*)malloc(n+1);
    for (int i=0;i<n;i++) res[i] = tolower(s[i]);
    res[n]='\0';
    return res;
}

char* maskVowels(const char* s) {
    int n = strlen(s);
    char* res = (char*)malloc(n+1);
    for (int i=0;i<n;i++) res[i] = isVowel(s[i]) ? '*' : tolower(s[i]);
    res[n]='\0';
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** spellchecker(char** wordlist, int wordlistSize, char** queries, int queriesSize, int* returnSize) {
    *returnSize = queriesSize;
    char** ans = (char**)malloc(queriesSize * sizeof(char*));

    // Build maps
    HashMap* exact = createMap();
    HashMap* lower = createMap();
    HashMap* vowel = createMap();

    for (int i=0;i<wordlistSize;i++) {
        char* w = wordlist[i];

        // Exact
        insertMap(exact, w, w);

        // Lower
        char* lw = toLowerStr(w);
        insertMap(lower, lw, w);
        free(lw);

        // Vowel
        char* vw = maskVowels(w);
        insertMap(vowel, vw, w);
        free(vw);
    }

    // Process queries
    for (int q=0;q<queriesSize;q++) {
        char* query = queries[q];
        char* res = NULL;

        // Exact
        res = getMap(exact, query);

        // Case-insensitive
        if (!res) {
            char* lq = toLowerStr(query);
            res = getMap(lower, lq);
            free(lq);
        }

        // Vowel-error
        if (!res) {
            char* vq = maskVowels(query);
            res = getMap(vowel, vq);
            free(vq);
        }

        ans[q] = res ? strdup(res) : strdup("");
    }

    return ans;
}
