class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);   // use stringstream to split by spaces
        string token;
        int prev = -1;        // previous number, start with -1 since numbers are positive

        while (ss >> token) {
            if (isdigit(token[0])) {  // if token starts with a digit, it's a number
                int num = stoi(token);
                if (num <= prev) {   // not strictly increasing
                    return false;
                }
                prev = num;
            }
        }
        return true;  // all numbers strictly increasing
    }
};
