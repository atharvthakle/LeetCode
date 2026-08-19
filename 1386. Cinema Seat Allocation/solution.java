class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, Integer> rows = new HashMap<>();

        for (int[] seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            if (s >= 2 && s <= 9) {
                rows.put(row, rows.getOrDefault(row, 0) | (1 << s));
            }
        }

        long ans = (long) (n - rows.size()) * 2;

        int leftMask = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int rightMask = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (int mask : rows.values()) {
            boolean left = (mask & leftMask) == 0;
            boolean middle = (mask & middleMask) == 0;
            boolean right = (mask & rightMask) == 0;

            if (left && right) {
                ans += 2;
            } else if (left || middle || right) {
                ans += 1;
            }
        }

        return (int) ans;
    }
}
