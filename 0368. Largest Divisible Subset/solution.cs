public class Solution {
    public IList<int> LargestDivisibleSubset(int[] nums) {
        int n = nums.Length;
        Array.Sort(nums);

        int[] dp = new int[n];
        int[] parent = new int[n];

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            parent[i] = -1;
        }

        int maxLen = 1;
        int maxIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }

        // Reconstruct the subset
        List<int> result = new List<int>();
        int curr = maxIndex;
        while (curr != -1) {
            result.Add(nums[curr]);
            curr = parent[curr];
        }

        result.Reverse();
        return result;
    }
}
