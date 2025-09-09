#define MOD 1000000007

int peopleAwareOfSecret(int n, int delay, int forget) {
    long dp[n + 1];
    for (int i = 0; i <= n; i++) dp[i] = 0;
    
    dp[1] = 1;  // On day 1, one person knows the secret
    
    for (int day = 1; day <= n; day++) {
        long share = dp[day];  // People who learned secret on "day"
        
        // They will start sharing after "delay"
        int start = day + delay;
        int end = day + forget;  // They forget on this day, so stop before
        
        for (int j = start; j < end && j <= n; j++) {
            dp[j] = (dp[j] + share) % MOD;
        }
    }
    
    // Count people who still know the secret at day n
    long ans = 0;
    for (int i = n - forget + 1; i <= n; i++) {
        if (i >= 1) ans = (ans + dp[i]) % MOD;
    }
    
    return (int)ans;
}
