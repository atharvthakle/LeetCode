#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;

            // Count frequency for current window
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            // Convert to vector of pairs (value, frequency)
            vector<pair<int, int>> elements(freq.begin(), freq.end());

            // Sort by frequency (desc), then value (desc)
            sort(elements.begin(), elements.end(), [](auto &a, auto &b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });

            // Compute x-sum
            int count = 0;
            int sum = 0;
            for (auto &p : elements) {
                if (count >= x) break;
                sum += p.first * p.second;
                count++;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
