#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (auto &op : operations) {
            if (op.find("++") != string::npos) {
                X++;
            } else {
                X--;
            }
        }
        return X;
    }
};
