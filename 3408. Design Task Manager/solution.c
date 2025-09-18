#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------------- Task struct ----------------
typedef struct {
    int userId;
    int taskId;
    int priority;
    int valid; // 1 if task is active, 0 if removed/overwritten
} TaskInfo;

// ---------------- Hash map (taskId -> TaskInfo*) ----------------
typedef struct TaskNode {
    int taskId;
    TaskInfo* info;
    struct TaskNode* next;
} TaskNode;

#define HASH_SIZE 200003
static TaskNode* taskHash[HASH_SIZE];

static unsigned long hashFunc(int key) {
    return (unsigned long)key % HASH_SIZE;
}

static void hashInsert(int taskId, TaskInfo* info) {
    unsigned long h = hashFunc(taskId);
    TaskNode* node = (TaskNode*)malloc(sizeof(TaskNode));
    node->taskId = taskId;
    node->info = info;
    node->next = taskHash[h];
    taskHash[h] = node;
}

static TaskInfo* hashGet(int taskId) {
    unsigned long h = hashFunc(taskId);
    TaskNode* cur = taskHash[h];
    while (cur) {
        if (cur->taskId == taskId) return cur->info;
        cur = cur->next;
    }
    return NULL;
}

// ---------------- Max Heap ----------------
typedef struct {
    int taskId;
    int userId;
    int priority;
} HeapNode;

typedef struct {
    HeapNode* arr;
    int size;
    int cap;
} Heap;

static int cmpNode(HeapNode* a, HeapNode* b) {
    if (a->priority != b->priority) return a->priority - b->priority; // higher priority wins
    return a->taskId - b->taskId; // if tie, higher taskId wins
}

static Heap* createHeap(int cap) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->arr = (HeapNode*)malloc(sizeof(HeapNode) * cap);
    h->size = 0;
    h->cap = cap;
    return h;
}

static void heapSwap(HeapNode* a, HeapNode* b) {
    HeapNode tmp = *a; *a = *b; *b = tmp;
}

static void heapPush(Heap* h, int taskId, int userId, int priority) {
    if (h->size == h->cap) {
        h->cap *= 2;
        h->arr = (HeapNode*)realloc(h->arr, sizeof(HeapNode) * h->cap);
    }
    h->arr[h->size].taskId = taskId;
    h->arr[h->size].userId = userId;
    h->arr[h->size].priority = priority;
    int i = h->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (cmpNode(&h->arr[i], &h->arr[p]) > 0) {
            heapSwap(&h->arr[i], &h->arr[p]);
            i = p;
        } else break;
    }
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

static HeapNode heapTop(Heap* h) { return h->arr[0]; }

// ---------------- TaskManager ----------------
typedef struct {
    Heap* heap;
} TaskManager;

TaskManager* taskManagerCreate(int** tasks, int tasksSize, int* tasksColSize) {
    for (int i = 0; i < HASH_SIZE; i++) taskHash[i] = NULL;
    TaskManager* obj = (TaskManager*)malloc(sizeof(TaskManager));
    obj->heap = createHeap(4);

    for (int i = 0; i < tasksSize; i++) {
        int userId = tasks[i][0];
        int taskId = tasks[i][1];
        int priority = tasks[i][2];
        TaskInfo* info = (TaskInfo*)malloc(sizeof(TaskInfo));
        info->userId = userId;
        info->taskId = taskId;
        info->priority = priority;
        info->valid = 1;
        hashInsert(taskId, info);
        heapPush(obj->heap, taskId, userId, priority);
    }
    return obj;
}

void taskManagerAdd(TaskManager* obj, int userId, int taskId, int priority) {
    TaskInfo* info = (TaskInfo*)malloc(sizeof(TaskInfo));
    info->userId = userId;
    info->taskId = taskId;
    info->priority = priority;
    info->valid = 1;
    hashInsert(taskId, info);
    heapPush(obj->heap, taskId, userId, priority);
}

void taskManagerEdit(TaskManager* obj, int taskId, int newPriority) {
    TaskInfo* info = hashGet(taskId);
    if (!info) return;
    info->priority = newPriority;
    heapPush(obj->heap, taskId, info->userId, newPriority);
}

void taskManagerRmv(TaskManager* obj, int taskId) {
    TaskInfo* info = hashGet(taskId);
    if (!info) return;
    info->valid = 0; // lazy delete
}

int taskManagerExecTop(TaskManager* obj) {
    Heap* h = obj->heap;
    while (h->size > 0) {
        HeapNode top = heapTop(h);
        TaskInfo* info = hashGet(top.taskId);
        if (info && info->valid && info->priority == top.priority) {
            int userId = info->userId;
            info->valid = 0; // remove executed task
            heapPop(h);
            return userId;
        }
        heapPop(h);
    }
    return -1;
}

void taskManagerFree(TaskManager* obj) {
    if (!obj) return;
    if (obj->heap) {
        if (obj->heap->arr) free(obj->heap->arr);
        free(obj->heap);
    }
    for (int i = 0; i < HASH_SIZE; i++) {
        TaskNode* cur = taskHash[i];
        while (cur) {
            TaskNode* nxt = cur->next;
            if (cur->info) free(cur->info);
            free(cur);
            cur = nxt;
        }
        taskHash[i] = NULL;
    }
    free(obj);
}
