public class Solution {
    public bool CanMeasureWater(int x, int y, int target) {
        if (target == 0) return true;
        if (x + y < target) return false;

        return target % GCD(x, y) == 0;
    }

    private int GCD(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}
