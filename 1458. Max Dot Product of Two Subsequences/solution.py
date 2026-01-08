class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        
        # Initialize dp with very small values
        dp = [[-10**18] * (m + 1) for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                prod = nums1[i - 1] * nums2[j - 1]
                
                dp[i][j] = max(
                    prod,                      # start new subsequence
                    dp[i - 1][j - 1] + prod,   # extend subsequence
                    dp[i - 1][j],              # skip nums1
                    dp[i][j - 1]               # skip nums2
                )
        
        return dp[n][m]
