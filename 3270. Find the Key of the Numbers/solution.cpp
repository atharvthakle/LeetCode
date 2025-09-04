#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        // Convert to 4-digit strings with leading zeros
        string s1 = string(4 - to_string(num1).length(), '0') + to_string(num1);
        string s2 = string(4 - to_string(num2).length(), '0') + to_string(num2);
        string s3 = string(4 - to_string(num3).length(), '0') + to_string(num3);

        string key = "";
        for (int i = 0; i < 4; i++) {
            char digit = min({s1[i], s2[i], s3[i]});
            key.push_back(digit);
        }

        // Remove leading zeros
        int idx = 0;
        while (idx < 4 && key[idx] == '0') idx++;
        if (idx == 4) return 0; // all zeros

        return stoi(key.substr(idx));
    }
};
