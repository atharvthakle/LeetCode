// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int ans = n;  // assume last version is bad by default

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                ans = mid;          // mid could be the first bad version
                right = mid - 1;    // search earlier versions
            } else {
                left = mid + 1;     // search later versions
            }
        }

        return ans;
    }
};
