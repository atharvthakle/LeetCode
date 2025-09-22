class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0); // since 1 <= nums[i] <= 100
        int maxFreq = 0;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        // Sum all elements that have the max frequency
        int total = 0;
        for (int f : freq) {
            if (f == maxFreq) total += f;
        }

        return total;
    }
};
