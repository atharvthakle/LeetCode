#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int source;
    int dest;
    int ts;
} Packet;

// ===== Queue for FIFO =====
typedef struct {
    Packet *arr;
    int front, rear, size, cap;
} Queue;

Queue* createQueue(int cap) {
    Queue* q = malloc(sizeof(Queue));
    q->arr = malloc(sizeof(Packet) * cap);
    q->cap = cap; q->size = 0; q->front = 0; q->rear = -1;
    return q;
}

void enqueue(Queue* q, Packet p) {
    q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = p;
    q->size++;
}

Packet dequeue(Queue* q) {
    Packet p = q->arr[q->front];
    q->front = (q->front + 1) % q->cap;
    q->size--;
    return p;
}

Packet* front(Queue* q) {
    return q->size ? &q->arr[q->front] : NULL;
}

// ===== Hash for duplicate check =====
#define HASH_SIZE 262144  // ~2^18, larger than max packets
typedef struct {
    int used;
    int s, d, t;
} HashEntry;

typedef struct {
    HashEntry *table;
} HashSet;

unsigned long hashKey(int s, int d, int t) {
    return ((unsigned long)s * 1315423911u + (unsigned long)d * 2654435761u + t) & (HASH_SIZE - 1);
}

HashSet* createHash() {
    HashSet* h = malloc(sizeof(HashSet));
    h->table = calloc(HASH_SIZE, sizeof(HashEntry));
    return h;
}

bool hashInsert(HashSet* h, int s, int d, int t) {
    unsigned long idx = hashKey(s,d,t);
    for(int i=0;i<HASH_SIZE;i++) {
        unsigned long j = (idx+i) & (HASH_SIZE-1);
        if(!h->table[j].used) {
            h->table[j].used=1; h->table[j].s=s; h->table[j].d=d; h->table[j].t=t;
            return true;
        }
        if(h->table[j].s==s && h->table[j].d==d && h->table[j].t==t) return false;
    }
    return false;
}

void hashRemove(HashSet* h, int s, int d, int t) {
    unsigned long idx = hashKey(s,d,t);
    for(int i=0;i<HASH_SIZE;i++) {
        unsigned long j = (idx+i) & (HASH_SIZE-1);
        if(h->table[j].used && h->table[j].s==s && h->table[j].d==d && h->table[j].t==t) {
            h->table[j].used=0;
            return;
        }
    }
}

// ===== Destination arrays =====
typedef struct {
    int *ts;
    int size, cap;
    int front; // index of first valid
} DestArray;

DestArray* createDestArray() {
    DestArray* da = malloc(sizeof(DestArray));
    da->cap=4; da->size=0; da->front=0;
    da->ts=malloc(sizeof(int)*da->cap);
    return da;
}

void pushDest(DestArray* da, int t) {
    if(da->size==da->cap) {
        da->cap*=2;
        da->ts=realloc(da->ts,sizeof(int)*da->cap);
    }
    da->ts[da->size++]=t;
}

void popDest(DestArray* da) { // pop from front
    da->front++;
}

int countInRange(DestArray* da, int start, int end) {
    if(da->front>=da->size) return 0;
    int* arr=da->ts;
    int l=da->front, r=da->size-1;
    // lower_bound >= start
    int low=r+1;
    int lo=l, hi=r;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(arr[mid]>=start){ low=mid; hi=mid-1; }
        else lo=mid+1;
    }
    // upper_bound > end
    int high=l-1;
    lo=l; hi=r;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(arr[mid]<=end){ high=mid; lo=mid+1; }
        else hi=mid-1;
    }
    if(low>high) return 0;
    return high-low+1;
}

// ===== Router =====
typedef struct {
    int mem;
    Queue* q;
    HashSet* dup;
    DestArray** dests;
} Router;

Router* routerCreate(int memoryLimit) {
    Router* r = malloc(sizeof(Router));
    r->mem=memoryLimit;
    r->q=createQueue(memoryLimit);
    r->dup=createHash();
    r->dests=calloc(200001,sizeof(DestArray*));
    return r;
}

bool routerAddPacket(Router* r, int s, int d, int t) {
    if(!hashInsert(r->dup,s,d,t)) return false; // duplicate
    if(r->q->size==r->mem) { // evict oldest
        Packet old=dequeue(r->q);
        hashRemove(r->dup,old.source,old.dest,old.ts);
        if(r->dests[old.dest]) popDest(r->dests[old.dest]);
    }
    Packet p={s,d,t};
    enqueue(r->q,p);
    if(!r->dests[d]) r->dests[d]=createDestArray();
    pushDest(r->dests[d],t);
    return true;
}

int* routerForwardPacket(Router* r, int* retSize) {
    if(r->q->size==0){ *retSize=0; return NULL; }
    Packet p=dequeue(r->q);
    hashRemove(r->dup,p.source,p.dest,p.ts);
    if(r->dests[p.dest]) popDest(r->dests[p.dest]);
    int* out=malloc(sizeof(int)*3);
    out[0]=p.source; out[1]=p.dest; out[2]=p.ts;
    *retSize=3;
    return out;
}

int routerGetCount(Router* r, int dest, int start, int end) {
    if(!r->dests[dest]) return 0;
    return countInRange(r->dests[dest],start,end);
}

void routerFree(Router* r) {
    free(r->q->arr); free(r->q);
    free(r->dup->table); free(r->dup);
    for(int i=0;i<=200000;i++) if(r->dests[i]){ free(r->dests[i]->ts); free(r->dests[i]); }
    free(r->dests); free(r);
}
