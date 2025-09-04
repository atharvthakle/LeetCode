class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true; // 1 is a perfect square
        
        long long left = 1, right = num / 2;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sq = mid * mid;
            
            if (sq == num) return true;
            else if (sq < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
