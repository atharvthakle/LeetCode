class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string next = "";
            for (int i = 0; i < s.size(); i += k) {
                int sum = 0;
                // take substring of size <= k
                for (int j = i; j < i + k && j < s.size(); j++) {
                    sum += s[j] - '0';
                }
                // append sum as string
                next += to_string(sum);
            }
            s = next;
        }
        return s;
    }
};
