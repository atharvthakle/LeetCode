class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        bool hasFirst = false, hasSecond = false, hasThird = false;

        for (int num : nums) {
            if ((hasFirst && num == first) || (hasSecond && num == second) || (hasThird && num == third))
                continue;  // skip duplicates

            if (!hasFirst || num > first) {
                third = second; hasThird = hasSecond;
                second = first; hasSecond = hasFirst;
                first = num; hasFirst = true;
            }
            else if (!hasSecond || num > second) {
                third = second; hasThird = hasSecond;
                second = num; hasSecond = true;
            }
            else if (!hasThird || num > third) {
                third = num; hasThird = true;
            }
        }

        return hasThird ? third : first;
    }
};
