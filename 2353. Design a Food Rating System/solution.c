#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------- Simple Hash for food -> index -------------------
typedef struct FoodIndex {
    char* food;
    int index;
    struct FoodIndex* next;
} FoodIndex;

#define HASH_SIZE 20011
static FoodIndex* foodHash[HASH_SIZE];

static unsigned long hashFunc(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) hash = ((hash << 5) + hash) + (unsigned char)c;
    return hash % HASH_SIZE;
}

static void foodHashInsert(const char* food, int index) {
    unsigned long h = hashFunc(food);
    FoodIndex* node = (FoodIndex*)malloc(sizeof(FoodIndex));
    node->food = strdup(food);
    node->index = index;
    node->next = foodHash[h];
    foodHash[h] = node;
}

static int foodHashGet(const char* food) {
    unsigned long h = hashFunc(food);
    FoodIndex* cur = foodHash[h];
    while (cur) {
        if (strcmp(cur->food, food) == 0) return cur->index;
        cur = cur->next;
    }
    return -1;
}

// ------------------- Max-Heap per cuisine -------------------
typedef struct {
    char* food;
    int rating;
} HeapNode;

typedef struct {
    HeapNode* arr;
    int size;
    int cap;
} Heap;

static Heap* createHeap(int cap) {
    if (cap < 4) cap = 4;
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->arr = (HeapNode*)malloc(sizeof(HeapNode) * cap);
    h->size = 0;
    h->cap = cap;
    return h;
}

// comparator: positive means a is "greater" (should be closer to top)
static int cmpNode(const HeapNode* a, const HeapNode* b) {
    if (a->rating != b->rating)
        return a->rating - b->rating; // higher rating => greater
    // if equal rating, lexicographically smaller food should win:
    // return >0 if a < b lexicographically (so a considered greater)
    // strcmp(a,b) < 0 when a < b; we want positive then => return -strcmp(a,b)
    return -strcmp(a->food, b->food);
}

static void heapSwap(HeapNode* A, HeapNode* B) {
    HeapNode tmp = *A;
    *A = *B;
    *B = tmp;
}

static void heapPush(Heap* h, char* food, int rating) {
    if (h->size == h->cap) {
        int newcap = h->cap * 2;
        HeapNode* n = (HeapNode*)realloc(h->arr, sizeof(HeapNode) * newcap);
        if (!n) return; // out of memory (shouldn't happen on LeetCode)
        h->arr = n;
        h->cap = newcap;
    }
    h->arr[h->size].food = food;
    h->arr[h->size].rating = rating;
    int i = h->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (cmpNode(&h->arr[i], &h->arr[p]) > 0) {
            heapSwap(&h->arr[i], &h->arr[p]);
            i = p;
        } else break;
    }
}

static HeapNode heapTop(Heap* h) {
    return h->arr[0];
}

static void heapPop(Heap* h) {
    if (h->size == 0) return;
    h->arr[0] = h->arr[--h->size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, best = i;
        if (l < h->size && cmpNode(&h->arr[l], &h->arr[best]) > 0) best = l;
        if (r < h->size && cmpNode(&h->arr[r], &h->arr[best]) > 0) best = r;
        if (best != i) {
            heapSwap(&h->arr[i], &h->arr[best]);
            i = best;
        } else break;
    }
}

// ------------------- FoodRatings Class -------------------
typedef struct {
    char** foods;    // original food names
    char** cuisines; // cuisine per food
    int* ratings;    // current rating per food
    int n;

    // Per-cuisine structures:
    char** cuisineNames;
    Heap** cuisineHeaps;
    int cuisineCount;
} FoodRatings;

static int findCuisineIndex(FoodRatings* obj, const char* cuisine) {
    for (int i = 0; i < obj->cuisineCount; ++i) {
        if (strcmp(obj->cuisineNames[i], cuisine) == 0) return i;
    }
    return -1;
}

FoodRatings* foodRatingsCreate(char** foods, int foodsSize, char** cuisines, int cuisinesSize, int* ratings, int ratingsSize) {
    // clear hash
    for (int i = 0; i < HASH_SIZE; ++i) foodHash[i] = NULL;

    FoodRatings* obj = (FoodRatings*)malloc(sizeof(FoodRatings));
    obj->n = foodsSize;
    obj->foods = (char**)malloc(sizeof(char*) * foodsSize);
    obj->cuisines = (char**)malloc(sizeof(char*) * foodsSize);
    obj->ratings = (int*)malloc(sizeof(int) * foodsSize);
    obj->cuisineNames = (char**)malloc(sizeof(char*) * foodsSize);
    obj->cuisineHeaps = (Heap**)malloc(sizeof(Heap*) * foodsSize);
    obj->cuisineCount = 0;

    for (int i = 0; i < foodsSize; ++i) {
        obj->foods[i] = strdup(foods[i]);
        obj->cuisines[i] = strdup(cuisines[i]);
        obj->ratings[i] = ratings[i];

        // map food -> index for fast lookup later
        foodHashInsert(obj->foods[i], i);

        // find or create cuisine heap
        int cidx = findCuisineIndex(obj, cuisines[i]);
        if (cidx == -1) {
            cidx = obj->cuisineCount;
            obj->cuisineNames[cidx] = strdup(cuisines[i]);
            obj->cuisineHeaps[cidx] = createHeap(4); // small start; will grow as needed
            obj->cuisineCount++;
        }
        // push the food into cuisine heap
        heapPush(obj->cuisineHeaps[cidx], obj->foods[i], ratings[i]);
    }

    return obj;
}

void foodRatingsChangeRating(FoodRatings* obj, char* food, int newRating) {
    int idx = foodHashGet(food);
    if (idx < 0) return;
    obj->ratings[idx] = newRating;
    int cidx = findCuisineIndex(obj, obj->cuisines[idx]);
    if (cidx < 0) return;
    // push new entry; lazy deletion will discard old entries when popping top
    heapPush(obj->cuisineHeaps[cidx], obj->foods[idx], newRating);
}

char* foodRatingsHighestRated(FoodRatings* obj, char* cuisine) {
    int cidx = findCuisineIndex(obj, cuisine);
    if (cidx < 0) return strdup("");
    Heap* h = obj->cuisineHeaps[cidx];
    while (h->size > 0) {
        HeapNode top = heapTop(h);
        int idx = foodHashGet(top.food);
        if (idx >= 0 && obj->ratings[idx] == top.rating) {
            return top.food;
        }
        heapPop(h);
    }
    // shouldn't really happen given constraints, but return empty
    return strdup("");
}

void foodRatingsFree(FoodRatings* obj) {
    if (!obj) return;
    // Free foods, cuisines, cuisineNames, heaps (partial)
    for (int i = 0; i < obj->n; ++i) {
        if (obj->foods[i]) free(obj->foods[i]);
        if (obj->cuisines[i]) free(obj->cuisines[i]);
    }
    for (int i = 0; i < obj->cuisineCount; ++i) {
        if (obj->cuisineNames[i]) free(obj->cuisineNames[i]);
        if (obj->cuisineHeaps[i]) {
            free(obj->cuisineHeaps[i]->arr);
            free(obj->cuisineHeaps[i]);
        }
    }
    free(obj->foods);
    free(obj->cuisines);
    free(obj->ratings);
    free(obj->cuisineNames);
    free(obj->cuisineHeaps);

    // free hash entries
    for (int i = 0; i < HASH_SIZE; ++i) {
        FoodIndex* cur = foodHash[i];
        while (cur) {
            FoodIndex* nx = cur->next;
            if (cur->food) free(cur->food);
            free(cur);
            cur = nx;
        }
        foodHash[i] = NULL;
    }

    free(obj);
}

/*
 * The expected calling pattern on LeetCode:
 *
 * FoodRatings* obj = foodRatingsCreate(foods, foodsSize, cuisines, cuisinesSize, ratings, ratingsSize);
 * foodRatingsChangeRating(obj, food, newRating);
 * char* res = foodRatingsHighestRated(obj, cuisine); // res points to internal strdup'd string in our structure (or new strdup "")
 * foodRatingsFree(obj);
 *
 * Note: LeetCode's harness expects char* return that points to a valid C-string.
 */
