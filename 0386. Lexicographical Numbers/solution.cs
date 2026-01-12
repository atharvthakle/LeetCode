public class Solution {
    public IList<int> LexicalOrder(int n) {
        List<int> result = new List<int>(n);
        
        int curr = 1;
        for (int i = 0; i < n; i++) {
            result.Add(curr);
            
            if (curr * 10 <= n) {
                // Go to next depth
                curr *= 10;
            } 
            else {
                // Otherwise, move to next valid sibling
                while (curr % 10 == 9 || curr + 1 > n) {
                    curr /= 10; // climb up
                }
                curr++;
            }
        }
        
        return result;
    }
}
