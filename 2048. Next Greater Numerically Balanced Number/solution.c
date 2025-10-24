#include <stdbool.h>

bool isBeautiful(int x) {
    int freq[10] = {0};
    int t = x;
    while (t > 0) {
        freq[t % 10]++;
        t /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (freq[i] > 0 && freq[i] != i)
            return false;
    }
    return true;
}

int nextBeautifulNumber(int n) {
    int x = n + 1;
    while (1) {
        if (isBeautiful(x))
            return x;
        x++;
    }
}
