public class Solution {
    public int CountCollisions(string directions) {
        int n = directions.Length;
        int left = 0, right = n - 1;

        // Skip all leading L's
        while (left < n && directions[left] == 'L')
            left++;

        // Skip all trailing R's
        while (right >= 0 && directions[right] == 'R')
            right--;

        int collisions = 0;

        // Count moving cars ('L' or 'R') in the middle
        for (int i = left; i <= right; i++)
        {
            if (directions[i] == 'L' || directions[i] == 'R')
                collisions++;
        }

        return collisions;
    }
}
