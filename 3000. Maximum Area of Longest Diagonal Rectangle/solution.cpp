class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagSq = -1; // store max diagonal squared
        int maxArea = -1;   // store max area for that diagonal
        
        for (auto &d : dimensions) {
            int l = d[0], w = d[1];
            int diagSq = l * l + w * w; // diagonal squared
            int area = l * w;
            
            if (diagSq > maxDiagSq) {
                maxDiagSq = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiagSq) {
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};
