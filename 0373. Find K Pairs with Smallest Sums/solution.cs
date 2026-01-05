public class Solution {
    public IList<IList<int>> KSmallestPairs(int[] nums1, int[] nums2, int k) {
        var result = new List<IList<int>>();
        if (nums1.Length == 0 || nums2.Length == 0 || k == 0)
            return result;

        // Min-heap: (sum, i, j)
        var pq = new PriorityQueue<(int i, int j), long>();

        // Initialize heap with first column
        for (int i = 0; i < Math.Min(nums1.Length, k); i++) {
            pq.Enqueue((i, 0), (long)nums1[i] + nums2[0]);
        }

        while (k-- > 0 && pq.Count > 0) {
            var (i, j) = pq.Dequeue();
            result.Add(new List<int> { nums1[i], nums2[j] });

            // Push next element in nums2
            if (j + 1 < nums2.Length) {
                pq.Enqueue((i, j + 1), (long)nums1[i] + nums2[j + 1]);
            }
        }

        return result;
    }
}
