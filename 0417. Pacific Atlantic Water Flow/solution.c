#include <stdlib.h>
#include <stdbool.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

void dfs(int** heights, int m, int n, int r, int c, bool** visited) {
    visited[r][c] = true;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0; i < 4; i++) {
        int nr = r + dirs[i][0];
        int nc = c + dirs[i][1];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
        if (visited[nr][nc]) continue;
        if (heights[nr][nc] < heights[r][c]) continue;
        dfs(heights, m, n, nr, nc, visited);
    }
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    int m = heightsSize;
    int n = heightsColSize[0];
    *returnSize = 0;
    
    bool** pacific = (bool**)malloc(m * sizeof(bool*));
    bool** atlantic = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        pacific[i] = (bool*)calloc(n, sizeof(bool));
        atlantic[i] = (bool*)calloc(n, sizeof(bool));
    }

    // Pacific: top and left borders
    for (int i = 0; i < m; i++)
        dfs(heights, m, n, i, 0, pacific);
    for (int j = 0; j < n; j++)
        dfs(heights, m, n, 0, j, pacific);

    // Atlantic: bottom and right borders
    for (int i = 0; i < m; i++)
        dfs(heights, m, n, i, n - 1, atlantic);
    for (int j = 0; j < n; j++)
        dfs(heights, m, n, m - 1, j, atlantic);

    // Count results
    int capacity = m * n;
    int** res = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                res[*returnSize] = (int*)malloc(2 * sizeof(int));
                res[*returnSize][0] = i;
                res[*returnSize][1] = j;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }
        }
    }

    // Cleanup visited arrays
    for (int i = 0; i < m; i++) {
        free(pacific[i]);
        free(atlantic[i]);
    }
    free(pacific);
    free(atlantic);

    return res;
}
