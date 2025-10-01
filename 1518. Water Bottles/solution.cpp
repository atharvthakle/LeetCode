class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            int newBottles = empty / numExchange;  // full bottles from exchange
            totalDrank += newBottles;
            empty = empty % numExchange + newBottles;  // leftover empties + new empties
        }

        return totalDrank;
    }
};
