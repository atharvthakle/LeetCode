int maximumEnergy(int* energy, int energySize, int k) {
    int dp[energySize];
    int maxEnergy = -1000000000; // very small number for initialization

    // Fill from the end to the beginning
    for (int i = energySize - 1; i >= 0; i--) {
        if (i + k < energySize)
            dp[i] = energy[i] + dp[i + k];
        else
            dp[i] = energy[i];

        if (dp[i] > maxEnergy)
            maxEnergy = dp[i];
    }

    return maxEnergy;
}
