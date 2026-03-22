public class Solution : SolBase {
    public int Rand10() {
        while (true) {
            int row = Rand7();
            int col = Rand7();

            int num = (row - 1) * 7 + col; // 1 to 49

            if (num <= 40) {
                return (num - 1) % 10 + 1;
            }
        }
    }
}
