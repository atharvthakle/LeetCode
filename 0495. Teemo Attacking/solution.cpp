#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty() || duration == 0) return 0;

        int total = 0;
        for (int i = 0; i < (int)timeSeries.size() - 1; i++) {
            total += min(duration, timeSeries[i+1] - timeSeries[i]);
        }
        total += duration; // last attack always full duration
        return total;
    }
};
