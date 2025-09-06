int numTrees(int n) {
    int dp[n + 1];
    dp[0] = 1;  // empty tree
    dp[1] = 1;  // single node tree

    for (int nodes = 2; nodes <= n; nodes++) {
        dp[nodes] = 0;
        for (int root = 1; root <= nodes; root++) {
            dp[nodes] += dp[root - 1] * dp[nodes - root];
        }
    }

    return dp[n];
}
