public class Solution {
    public int BestClosingTime(string customers) {
        int n = customers.Length;

        // Initial penalty: if we close at hour 0,
        // all 'Y' customers cause penalty
        int penalty = 0;
        foreach (char c in customers)
            if (c == 'Y') penalty++;

        int minPenalty = penalty;
        int bestHour = 0;

        // Try closing at each hour j from 1 to n
        for (int j = 1; j <= n; j++) {
            // Hour j-1 moves from "closed" to "open"
            if (customers[j - 1] == 'Y')
                penalty--; // no longer a closed-hour penalty
            else
                penalty++; // now an open-hour penalty

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }

        return bestHour;
    }
}
