import java.util.*;

class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> res = new ArrayList<>();

        for (String q : queries) {
            for (String d : dictionary) {
                if (isValid(q, d)) {
                    res.add(q);
                    break; // no need to check more
                }
            }
        }

        return res;
    }

    private boolean isValid(String a, String b) {
        int diff = 0;

        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diff++;
                if (diff > 2) return false;
            }
        }

        return true;
    }
}
