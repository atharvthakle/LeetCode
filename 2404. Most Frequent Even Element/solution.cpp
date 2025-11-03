#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Count frequency of even numbers
        for (int n : nums) {
            if (n % 2 == 0)
                freq[n]++;
        }

        // If no even number found
        if (freq.empty()) return -1;

        int ans = -1;
        int maxFreq = 0;

        // Find the even number with highest frequency
        for (auto& [num, count] : freq) {
            if (count > maxFreq || (count == maxFreq && num < ans)) {
                maxFreq = count;
                ans = num;
            }
        }

        return ans;
    }
};
