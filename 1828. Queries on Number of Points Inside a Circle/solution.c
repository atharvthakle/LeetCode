#include <stdlib.h>

int* countPoints(int** points, int pointsSize, int* pointsColSize, 
                 int** queries, int queriesSize, int* queriesColSize, int* returnSize) {

    int* ans = (int*)malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; ++i) {
        int count = 0;
        int xj = queries[i][0];
        int yj = queries[i][1];
        int r = queries[i][2];
        int r2 = r * r; // compare squared distances

        for (int j = 0; j < pointsSize; ++j) {
            int dx = points[j][0] - xj;
            int dy = points[j][1] - yj;
            if (dx * dx + dy * dy <= r2)
                count++;
        }

        ans[i] = count;
    }

    return ans;
}
