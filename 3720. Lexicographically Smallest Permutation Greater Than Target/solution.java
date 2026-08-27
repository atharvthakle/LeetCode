class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int n = s.length();
        int[] cnt = new int[26];

        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }

        StringBuilder prefix = new StringBuilder();

        // First try to keep the prefix equal to target as long as possible.
        for (int i = 0; i < n; i++) {
            int t = target.charAt(i) - 'a';

            // If we can match target[i], continue building the prefix.
            if (cnt[t] > 0) {
                cnt[t]--;
                prefix.append(target.charAt(i));
            } else {
                break;
            }
        }

        // Try changing a position from right to left.
        for (int i = prefix.length(); i >= 0; i--) {
            int[] temp = cnt.clone();

            // If moving back, restore target characters after position i.
            for (int j = prefix.length() - 1; j >= i; j--) {
                temp[prefix.charAt(j) - 'a']++;
            }

            if (i == n) continue;

            int t = target.charAt(i) - 'a';

            // Find the smallest available character greater than target[i].
            for (int c = t + 1; c < 26; c++) {
                if (temp[c] > 0) {
                    StringBuilder ans = new StringBuilder();

                    // Keep prefix before i.
                    ans.append(prefix.substring(0, i));

                    // Put the smallest greater character.
                    ans.append((char) ('a' + c));
                    temp[c]--;

                    // Fill the rest with smallest characters.
                    for (int ch = 0; ch < 26; ch++) {
                        while (temp[ch] > 0) {
                            ans.append((char) ('a' + ch));
                            temp[ch]--;
                        }
                    }

                    return ans.toString();
                }
            }
        }

        return "";
    }
}
