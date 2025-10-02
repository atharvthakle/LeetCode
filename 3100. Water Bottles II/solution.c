int maxBottlesDrunk(int numBottles, int numExchange) {
    int total = numBottles;
    int empty = numBottles;

    while (empty >= numExchange) {
        // Perform exactly one exchange
        empty -= numExchange;
        numExchange++;   // cost increases for next exchange
        empty++;         // got one new full bottle -> drink it -> 1 empty
        total++;         // drank one more bottle
    }

    return total;
}
