#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xs;
        xs.reserve(points.size());
        
        for (auto &p : points) {
            xs.push_back(p[0]);
        }
        
        sort(xs.begin(), xs.end());
        
        int maxGap = 0;
        for (int i = 1; i < xs.size(); i++) {
            maxGap = max(maxGap, xs[i] - xs[i - 1]);
        }
        
        return maxGap;
    }
};      
