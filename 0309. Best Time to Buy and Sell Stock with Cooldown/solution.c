#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;
    
    int hold = -prices[0]; // profit holding stock
    int sold = 0;          // profit after selling stock
    int rest = 0;          // profit resting

    for (int i = 1; i < pricesSize; i++) {
        int prev_hold = hold;
        int prev_sold = sold;
        int prev_rest = rest;

        hold = max(prev_hold, prev_rest - prices[i]);
        sold = prev_hold + prices[i];
        rest = max(prev_rest, prev_sold);
    }

    return max(sold, rest);
}
