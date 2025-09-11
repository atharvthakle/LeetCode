#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int left = 0, right = (int)s.size() - 1;

        while (left < right) {
            // find left vowel
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            // find right vowel
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }
            // swap vowels
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};
