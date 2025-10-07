#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare_int(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* avoidFlood(int* rains, int rainsSize, int* returnSize) {
    if (rainsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Collect unique lakes
    int* all_lakes = (int*)malloc(rainsSize * sizeof(int));
    int num_events = 0;
    for (int i = 0; i < rainsSize; i++) {
        if (rains[i] > 0) {
            all_lakes[num_events++] = rains[i];
        }
    }

    if (num_events == 0) {
        int* ans = (int*)malloc(rainsSize * sizeof(int));
        memset(ans, 1, rainsSize * sizeof(int));  // Dry lake 1 arbitrarily
        *returnSize = rainsSize;
        free(all_lakes);
        return ans;
    }

    // Sort and unique
    qsort(all_lakes, num_events, sizeof(int), compare_int);
    int m = 0;
    for (int i = 0; i < num_events; i++) {
        if (i == 0 || all_lakes[i] != all_lakes[i - 1]) {
            all_lakes[m++] = all_lakes[i];
        }
    }
    if (m < num_events) {
        // Resize if needed, but for simplicity, we use up to m
    }

    // Map lake to id using binary search later

    // Count rains per lake
    int* counters = (int*)calloc(m, sizeof(int));
    for (int i = 0; i < rainsSize; i++) {
        if (rains[i] > 0) {
            // Binary search for id
            int low = 0, high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (all_lakes[mid] == rains[i]) {
                    counters[mid]++;
                    break;
                } else if (all_lakes[mid] < rains[i]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
    }

    // Lake rains days
    typedef struct {
        int* days;
        int size;
        int count;
    } LakeRains;
    LakeRains* lake_rains = (LakeRains*)malloc(m * sizeof(LakeRains));
    for (int j = 0; j < m; j++) {
        lake_rains[j].size = counters[j];
        lake_rains[j].count = 0;
        lake_rains[j].days = counters[j] > 0 ? (int*)malloc(counters[j] * sizeof(int)) : NULL;
    }
    free(counters);

    // Fill days
    for (int i = 0; i < rainsSize; i++) {
        if (rains[i] > 0) {
            int low = 0, high = m - 1;
            int id = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (all_lakes[mid] == rains[i]) {
                    id = mid;
                    break;
                } else if (all_lakes[mid] < rains[i]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (id != -1) {
                lake_rains[id].days[lake_rains[id].count++] = i;
            }
        }
    }

    // Now simulation
    int* full_status = (int*)calloc(m, sizeof(int));  // 1 if full
    int* next_rain_idx = (int*)calloc(m, sizeof(int));  // index of next rain day

    // Min heap for (next_rain_day, lake_id)
    typedef struct {
        int day;
        int lake_id;
    } HeapPair;
    HeapPair* min_heap = (HeapPair*)malloc(rainsSize * sizeof(HeapPair));
    int heap_size = 0;

    // Function to push to heap
    auto void push_heap(int day, int lake_id) {
        min_heap[heap_size] = (HeapPair){day, lake_id};
        int idx = heap_size++;
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (min_heap[parent].day <= min_heap[idx].day) break;
            HeapPair temp = min_heap[parent];
            min_heap[parent] = min_heap[idx];
            min_heap[idx] = temp;
            idx = parent;
        }
    }

    // Function to pop from heap
    auto int pop_heap() {
        if (heap_size == 0) return -1;
        int lake_id = min_heap[0].lake_id;
        heap_size--;
        if (heap_size > 0) {
            min_heap[0] = min_heap[heap_size];
            int idx = 0;
            while (1) {
                int left = 2 * idx + 1;
                int right = 2 * idx + 2;
                int smallest = idx;
                if (left < heap_size && min_heap[left].day < min_heap[smallest].day) {
                    smallest = left;
                }
                if (right < heap_size && min_heap[right].day < min_heap[smallest].day) {
                    smallest = right;
                }
                if (smallest == idx) break;
                HeapPair temp = min_heap[idx];
                min_heap[idx] = min_heap[smallest];
                min_heap[smallest] = temp;
                idx = smallest;
            }
        }
        return lake_id;
    }

    int* ans = (int*)malloc(rainsSize * sizeof(int));
    int possible = 1;

    for (int day = 0; day < rainsSize && possible; day++) {
        if (rains[day] > 0) {
            int lake = rains[day];
            // Find id
            int low = 0, high = m - 1;
            int id = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (all_lakes[mid] == lake) {
                    id = mid;
                    break;
                } else if (all_lakes[mid] < lake) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (id == -1) {
                // Lake not in our list? But it should be
                ans[day] = -1;
                continue;
            }
            if (full_status[id]) {
                possible = 0;
                break;
            }
            // Fill it
            full_status[id] = 1;
            // Schedule next rain if any
            int next_idx = next_rain_idx[id] + 1;
            if (next_idx < lake_rains[id].size) {
                int next_day = lake_rains[id].days[next_idx];
                push_heap(next_day, id);
                next_rain_idx[id] = next_idx;
            }
            ans[day] = -1;
        } else {
            // Dry day
            ans[day] = 1;  // Default
            if (heap_size > 0) {
                int dry_id = pop_heap();
                full_status[dry_id] = 0;
                ans[day] = all_lakes[dry_id];
                // Note: we don't push back the previous next, because we dried it, so the next rain will fill it again when it happens
            }
        }
    }

    // Cleanup
    for (int j = 0; j < m; j++) {
        if (lake_rains[j].days != NULL) {
            free(lake_rains[j].days);
        }
    }
    free(lake_rains);
    free(all_lakes);
    free(full_status);
    free(next_rain_idx);
    free(min_heap);

    if (!possible) {
        free(ans);
        *returnSize = 0;
        return NULL;
    }

    *returnSize = rainsSize;
    return ans;
}
