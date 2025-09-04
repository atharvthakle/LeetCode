class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;  // 0 -> 0, 1 -> 1

        long long left = 1, right = x / 2, ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid <= x) {
                ans = mid;
                left = mid + 1;  // try for bigger sqrt
            } else {
                right = mid - 1; // try smaller sqrt
            }
        }
        return (int)ans;
    }
};
