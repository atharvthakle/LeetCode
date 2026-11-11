class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long both = Math.min(need1, need2);
        long remaining1 = need1 - both;
        long remaining2 = need2 - both;

        long cost = both * Math.min(costBoth, cost1 + cost2);

        cost += remaining1 * Math.min(cost1, costBoth);
        cost += remaining2 * Math.min(cost2, costBoth);

        return cost;
    }
}
