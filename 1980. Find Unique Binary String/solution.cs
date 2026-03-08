public class Solution {
    public string FindDifferentBinaryString(string[] nums) {
        int n = nums.Length;
        char[] res = new char[n];

        for (int i = 0; i < n; i++) {
            res[i] = nums[i][i] == '0' ? '1' : '0';
        }

        return new string(res);
    }
}
