#include <stdio.h>

long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize,
                            int** topRight, int topRightSize, int* topRightColSize) {
    long long maxArea = 0;
    
    for (int i = 0; i < bottomLeftSize; i++) {
        for (int j = i + 1; j < bottomLeftSize; j++) {
            // Compute intersection coordinates
            long long x1 = bottomLeft[i][0] > bottomLeft[j][0] ? bottomLeft[i][0] : bottomLeft[j][0];
            long long y1 = bottomLeft[i][1] > bottomLeft[j][1] ? bottomLeft[i][1] : bottomLeft[j][1];
            long long x2 = topRight[i][0] < topRight[j][0] ? topRight[i][0] : topRight[j][0];
            long long y2 = topRight[i][1] < topRight[j][1] ? topRight[i][1] : topRight[j][1];
            
            // Check if they intersect
            if (x1 < x2 && y1 < y2) {
                long long width = x2 - x1;
                long long height = y2 - y1;
                long long side = width < height ? width : height; // max square side
                if (side > 0) {
                    long long area = side * side;
                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }
    }
    
    return maxArea;
}
