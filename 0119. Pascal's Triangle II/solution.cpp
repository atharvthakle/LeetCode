class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1); // initialize all elements to 1

        // Compute the inner elements using the previous values
        for (int i = 2; i <= rowIndex; ++i) {
            // Update from the end to avoid overwriting values we still need
            for (int j = i - 1; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }

        return row;
    }
};
