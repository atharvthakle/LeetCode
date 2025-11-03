int minCost(char* colors, int* neededTime, int neededTimeSize) {
    int totalTime = 0;

    for (int i = 1; i < neededTimeSize; i++) {
        if (colors[i] == colors[i - 1]) {
            // Remove the smaller one between the two same-colored consecutive balloons
            if (neededTime[i] < neededTime[i - 1]) {
                totalTime += neededTime[i];
                neededTime[i] = neededTime[i - 1]; // Keep the larger time (higher cost balloon remains)
            } else {
                totalTime += neededTime[i - 1];
            }
        }
    }

    return totalTime;
}
