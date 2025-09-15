int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total = 0;     // total gas - cost
    int tank = 0;      // current tank balance
    int start = 0;     // starting index

    for (int i = 0; i < gasSize; i++) {
        int diff = gas[i] - cost[i];
        total += diff;
        tank += diff;

        // If we can't reach next station, reset start
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    // If total gas < total cost, no solution
    return (total >= 0) ? start : -1;
}
