public class Solution {
    public string DecodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.Length;
        int cols = n / rows;

        char[] result = new char[n];
        int idx = 0;

        for (int startCol = 0; startCol < cols; startCol++) {
            int r = 0, c = startCol;

            while (r < rows && c < cols) {
                result[idx++] = encodedText[r * cols + c];
                r++;
                c++;
            }
        }

        // Remove trailing spaces
        int end = idx - 1;
        while (end >= 0 && result[end] == ' ') end--;

        return new string(result, 0, end + 1);
    }
}
