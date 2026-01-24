public class Solution {
    public int MinPairSum(int[] nums) {
        Array.Sort(nums);
        
        int l = 0, r = nums.Length - 1;
        int maxSum = 0;
        
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum > maxSum)
                maxSum = sum;
            
            l++;
            r--;
        }
        
        return maxSum;
    }
}
