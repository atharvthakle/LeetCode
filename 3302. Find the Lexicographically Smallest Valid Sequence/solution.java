class Solution {
    public int[] validSequence(String word1, String word2) {
        int m = word2.length();

        int[] ans = new int[m];
        int[] last = new int[m];

        java.util.Arrays.fill(last, -1);

        // last[j] = position in word1 used to match word2[j]
        // when matching word2[j..m-1] from the right.
        int i = word1.length() - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1.charAt(i) == word2.charAt(j)) {
                last[j] = i;
                j--;
            }
            i--;
        }

        boolean canChange = true;
        j = 0;

        for (i = 0; i < word1.length(); i++) {
            if (j == m) {
                break;
            }

            if (word1.charAt(i) == word2.charAt(j)) {
                ans[j++] = i;
            } 
            else if (canChange &&
                     (j == m - 1 || i < last[j + 1])) {
                ans[j++] = i;
                canChange = false;
            }
        }

        return j == m ? ans : new int[0];
    }
}
